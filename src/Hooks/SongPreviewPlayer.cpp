#include "main.hpp"
#include "Hooks/SongPreviewPlayer.hpp"

#include "GlobalNamespace/SongPreviewPlayer.hpp"

UnorderedEventCallback<bool*> MenuMusicPlayer::Hooks::previewPlayerWantsToPlayEvent;

MAKE_HOOK_MATCH(SongPreviewPlayer_CrossfadeTo, static_cast<void(GlobalNamespace::SongPreviewPlayer::*)(UnityEngine::AudioClip*, float, float, float, bool, System::Action*)>(&GlobalNamespace::SongPreviewPlayer::CrossfadeTo),
        void, GlobalNamespace::SongPreviewPlayer* self, UnityEngine::AudioClip* audioClip, float musicVolume, float startTime, float duration, bool isDefault, System::Action* onFadeOutCallback)
{
    bool allowPlayback = true;
    MenuMusicPlayer::Hooks::previewPlayerWantsToPlayEvent.invoke(&allowPlayback);
    if(allowPlayback)
        SongPreviewPlayer_CrossfadeTo(self, audioClip, musicVolume, startTime, duration, isDefault, onFadeOutCallback);
}

void MenuMusicPlayer::Hooks::InstallPreviewPlayerHooks()
{
    INSTALL_HOOK(getLogger(), SongPreviewPlayer_CrossfadeTo);
}