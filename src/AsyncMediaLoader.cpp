#include "main.hpp"
#include "AsyncMediaLoader.hpp"

#include "GlobalNamespace/CustomPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/MediaAsyncLoader.hpp"
#include "GlobalNamespace/StandardLevelInfoSaveData.hpp"

#include "custom-types/shared/delegate.hpp"

#include "System/Threading/CancellationToken.hpp"
#include "System/Threading/Tasks/Task_1.hpp"
#include "System/Action.hpp"

int coverImageCount, audioClipCount;

namespace MenuMusicPlayer::AsyncMediaLoader {

    void LoadCoverImageAsync(GlobalNamespace::IPreviewBeatmapLevel* level, std::function<void(UnityEngine::Sprite*)> onFinished)
    {
        auto cast = il2cpp_utils::try_cast<GlobalNamespace::CustomPreviewBeatmapLevel>(level);
        if(!cast.has_value())
            onFinished(nullptr);

        auto custom = cast.value();
        auto task = custom->GetCoverImageAsync(System::Threading::CancellationToken::get_None());

        // if they are NOT the same when the task finishes, then dont run callback as another task has been started
        int i = ++coverImageCount;
        task->GetAwaiter().OnCompleted(custom_types::MakeDelegate<System::Action*>(std::function([task, onFinished, i]()
        { if(coverImageCount == i) onFinished(task->get_Result()); })));
    }

    void LoadAudioClipAsync(GlobalNamespace::IPreviewBeatmapLevel* level, std::function<void(UnityEngine::AudioClip*)> onFinished)
    {
        auto cast = il2cpp_utils::try_cast<GlobalNamespace::CustomPreviewBeatmapLevel>(level);
        if(!cast.has_value())
            onFinished(nullptr);
            
        auto custom = cast.value();
        StringW file = custom->customLevelPath + "/" + custom->standardLevelInfoSaveData->songFilename;
        auto task = GlobalNamespace::MediaAsyncLoader::New_ctor()->LoadAudioClipFromFilePathAsync(file);

        // if they are NOT the same when the task finishes, then dont run callback as another task has been started
        int i = ++audioClipCount;
        task->GetAwaiter().OnCompleted(custom_types::MakeDelegate<System::Action*>(std::function([task, onFinished, i]()
        { if(audioClipCount == i) onFinished(task->get_Result()); })));
    }
}