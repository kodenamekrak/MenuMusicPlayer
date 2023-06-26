#pragma once

#include "custom-types/shared/macros.hpp"

#include "lapiz/shared/macros.hpp"

#include "/PlaybackController.hpp"
#include "PauseInputController.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/ImageView.hpp"
#include "HMUI/CurvedTextMeshPro.hpp"

#include "UnityEngine/UI/Button.hpp"

#include "bsml/shared/BSML/Components/Backgroundable.hpp"

DECLARE_CLASS_CODEGEN(MenuMusicPlayer, SongPlayerViewController, HMUI::ViewController,

    DECLARE_INSTANCE_FIELD_PRIVATE(PlaybackController*, _playbackController);
    DECLARE_INSTANCE_FIELD_PRIVATE(PauseInputController*, _pauseInputController);
    DECLARE_INSTANCE_FIELD(bool, hasActivated);

    DECLARE_INSTANCE_FIELD(BSML::Backgroundable*, mainContentVertical);
    DECLARE_INSTANCE_FIELD(BSML::Backgroundable*, songLoadingVertical);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, songCoverImage);
    DECLARE_INSTANCE_FIELD(HMUI::CurvedTextMeshPro*, songTitleText);
    DECLARE_INSTANCE_FIELD(HMUI::CurvedTextMeshPro*, songAuthorText);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, progressBarImage);
    DECLARE_INSTANCE_FIELD(HMUI::CurvedTextMeshPro*, songProgressText);
    DECLARE_INSTANCE_FIELD(HMUI::CurvedTextMeshPro*, songDurationText);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, previousButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, pauseButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, nextButton);

    DECLARE_INJECT_METHOD(void, Inject, PlaybackController* playbackController, PauseInputController* pauseInputController);
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::ViewController::DidActivate>::get(), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_INSTANCE_METHOD(void, PostParse);
    DECLARE_INSTANCE_METHOD(void, OnEnable);
    DECLARE_INSTANCE_METHOD(void, OnDisable);

    DECLARE_INSTANCE_METHOD(void, OnSongStart, GlobalNamespace::IPreviewBeatmapLevel* level);
    DECLARE_INSTANCE_METHOD(void, OnPreviewPlayerWantsToPlay, bool* allowPlayback);

    DECLARE_INSTANCE_METHOD(void, UpdatePauseButton);

    DECLARE_INSTANCE_METHOD(void, OnSongsLoaded);
    DECLARE_INSTANCE_METHOD(void, PreviousButtonPressed);
    DECLARE_INSTANCE_METHOD(void, PauseButtonPressed);
    DECLARE_INSTANCE_METHOD(void, NextButtonPressed);

    DECLARE_DEFAULT_CTOR();
)