#include "main.hpp"
#include "PlaybackController.hpp"

#include "AsyncMediaLoader.hpp"

DEFINE_TYPE(MenuMusicPlayer, PlaybackController);

namespace MenuMusicPlayer {

    void PlaybackController::Inject(GlobalNamespace::SongPreviewPlayer* songPreviewPlayer)
    {
        _songPreviewPlayer = songPreviewPlayer;
    }

    void PlaybackController::Start()
    {
        audioSource = get_gameObject()->AddComponent<UnityEngine::AudioSource*>();
        audioSource->set_playOnAwake(false);
    }

    void PlaybackController::Update()
    {
        if(audioSource->get_clip() && audioSource->get_time() >= audioSource->get_clip()->get_length())
            LoadNextSong();
    }

    void PlaybackController::Play()
    {
        _songPreviewPlayer->PauseCurrentChannel();
        audioSource->set_time(lastTime);
        audioSource->Play();
    }

    void PlaybackController::Pause()
    {
        audioSource->Pause();
        lastTime = audioSource->get_time();
        _songPreviewPlayer->UnPauseCurrentChannel();
        _songPreviewPlayer->CrossfadeToDefault();
    }

    void PlaybackController::LoadNextSong(bool playImmediately)
    {
        auto level = currentPlaylist[rand() % currentPlaylist.Length()];
        AsyncMediaLoader::LoadAudioClipAsync(level, [this, level, playImmediately](UnityEngine::AudioClip* audioClip)
        {
            if(!audioClip->m_CachedPtr.m_value)
                return LoadNextSong();
            audioSource->set_clip(audioClip);
            lastTime = 0;
            if(playImmediately)
                Play();
            onSongLoadedEvent.invoke(level);
        });
    }
}
