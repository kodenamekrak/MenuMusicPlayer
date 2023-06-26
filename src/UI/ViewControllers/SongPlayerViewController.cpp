#include "main.hpp"
#include "UI/ViewControllers/SongPlayerViewController.hpp"
#include "assets.hpp"
#include "Hooks/SongPreviewPlayer.hpp"
#include "AsyncMediaLoader.hpp"
#include "StringFormatter.hpp"

#include "bsml/shared/BSML.hpp"

#include "playlistcore/shared/PlaylistCore.hpp"

#include "songloader/shared/API.hpp"

DEFINE_TYPE(MenuMusicPlayer, SongPlayerViewController);

namespace MenuMusicPlayer {

    void SongPlayerViewController::Inject(PlaybackController* playbackController, PauseInputController* pauseInputController)
    {
        _playbackController = playbackController;
        _pauseInputController = pauseInputController;
    }

    void SongPlayerViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if(!firstActivation)
            return;
        
        _pauseInputController->menuButtonTriggeredEvent += std::bind(&SongPlayerViewController::PauseButtonPressed, this);
        Hooks::previewPlayerWantsToPlayEvent += std::bind(&SongPlayerViewController::OnPreviewPlayerWantsToPlay, this, std::placeholders::_1);
        BSML::parse_and_construct(IncludedAssets::SongPlayerViewController_bsml, get_transform(), this);
    }

    void SongPlayerViewController::PostParse()
    {
        if(!RuntimeSongLoader::API::HasLoadedSongs())
        {
            mainContentVertical->get_gameObject()->SetActive(false);
            RuntimeSongLoader::API::AddSongsLoadedEvent([this](auto _)
            {
                // Null check otherwise we crash after soft restart
                if(!m_CachedPtr.m_value)
                    return;
                OnSongsLoaded();
            });
        }
        else
            OnSongsLoaded();
        hasActivated = true;
    }

    void SongPlayerViewController::OnSongStart(GlobalNamespace::IPreviewBeatmapLevel* level)
    {
        UpdatePauseButton();
        songTitleText->SetText(level->get_songName());
        songAuthorText->SetText(level->get_songAuthorName());
        songDurationText->SetText(StringFormatter::TimeFormat(level->get_songDuration()));

        AsyncMediaLoader::LoadCoverImageAsync(level, [this](UnityEngine::Sprite* sprite)
        {
            songCoverImage->set_sprite(sprite);
        });
    }

    void SongPlayerViewController::OnSongsLoaded()
    {
        songLoadingVertical->get_gameObject()->SetActive(false);
        mainContentVertical->get_gameObject()->SetActive(true);

        _playbackController->currentPlaylist = PlaylistCore::GetLoadedPlaylists()[0]->playlistCS->beatmapLevelCollection->get_beatmapLevels();
        _playbackController->onSongLoadedEvent += std::bind(&SongPlayerViewController::OnSongStart, this, std::placeholders::_1);
        if(getModConfig().autoplay.GetValue())
        {
            _playbackController->LoadNextSong(getModConfig().autoplay.GetValue());
        }
    }

    void SongPlayerViewController::OnPreviewPlayerWantsToPlay(bool* allowPlayback)
    {
        if(_playbackController->audioSource->m_CachedPtr)
            *allowPlayback = !_playbackController->audioSource->get_isPlaying();
    }

    void SongPlayerViewController::PreviousButtonPressed()
    {}

    void SongPlayerViewController::PauseButtonPressed()
    {
        _playbackController->audioSource->get_isPlaying() ? _playbackController->Pause() : _playbackController->Play();
        UpdatePauseButton();
    }

    void SongPlayerViewController::NextButtonPressed()
    {
        _playbackController->LoadNextSong();
    }

    void SongPlayerViewController::UpdatePauseButton()
    {
        if(_playbackController->audioSource->get_isPlaying())
            pauseButton->GetComponentInChildren<HMUI::CurvedTextMeshPro*>()->SetText("Pause");
        else
            pauseButton->GetComponentInChildren<HMUI::CurvedTextMeshPro*>()->SetText("Resume");
    }

    void SongPlayerViewController::OnEnable()
    {
        if(!hasActivated)
            return;
        if(getModConfig().autoplay.GetValue())
            _playbackController->Play();
        UpdatePauseButton();
    }

    void SongPlayerViewController::OnDisable()
    {
        if(!hasActivated)
            return;
        _playbackController->Pause();
    }
}