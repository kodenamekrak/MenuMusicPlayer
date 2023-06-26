#pragma once

#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"

#include "UnityEngine/Sprite.hpp"
#include "UnityEngine/AudioClip.hpp"

namespace MenuMusicPlayer::AsyncMediaLoader {

    void LoadCoverImageAsync(GlobalNamespace::IPreviewBeatmapLevel* level, std::function<void(UnityEngine::Sprite*)> onFinished);

    void LoadAudioClipAsync(GlobalNamespace::IPreviewBeatmapLevel* level, std::function<void(UnityEngine::AudioClip*)> onFinished);
}