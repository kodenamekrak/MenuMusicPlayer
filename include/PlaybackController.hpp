#pragma once

#include "custom-types/shared/macros.hpp"

#include "lapiz/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/AudioClip.hpp"
#include "UnityEngine/AudioSource.hpp"

#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/SongPreviewPlayer.hpp"

DECLARE_CLASS_CODEGEN(MenuMusicPlayer, PlaybackController, UnityEngine::MonoBehaviour,

    DECLARE_INSTANCE_FIELD_PRIVATE(GlobalNamespace::SongPreviewPlayer*, _songPreviewPlayer);
    DECLARE_INSTANCE_FIELD(UnityEngine::AudioSource*, audioSource);
    DECLARE_INSTANCE_FIELD(ArrayW<GlobalNamespace::IPreviewBeatmapLevel*>, currentPlaylist);
    DECLARE_INSTANCE_FIELD(float, lastTime);

    UnorderedEventCallback<GlobalNamespace::IPreviewBeatmapLevel*> onSongLoadedEvent;

    DECLARE_INJECT_METHOD(void, Inject, GlobalNamespace::SongPreviewPlayer* songPreviewPlayer);
    DECLARE_INSTANCE_METHOD(void, Start);
    DECLARE_INSTANCE_METHOD(void, Update);

    DECLARE_INSTANCE_METHOD(void, Play);
    DECLARE_INSTANCE_METHOD(void, Pause);

    DECLARE_INSTANCE_METHOD(void, LoadNextSong, bool playImmediately = true);

    DECLARE_DEFAULT_CTOR();
)