#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"

namespace MenuMusicPlayer::Hooks {

    extern UnorderedEventCallback<bool*> previewPlayerWantsToPlayEvent;

    void InstallPreviewPlayerHooks();
}