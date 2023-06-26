#pragma once

#include "custom-types/shared/macros.hpp"

#include "HMUI/FlowCoordinator.hpp"

#include "ViewControllers/SettingsViewController.hpp"

#include "lapiz/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(MenuMusicPlayer, SettingsFlowCoordinator, HMUI::FlowCoordinator,

    DECLARE_INSTANCE_FIELD_PRIVATE(SettingsViewController*, _settingsViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::DidActivate>::get(), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::BackButtonWasPressed>::get(), HMUI::ViewController* topViewController);

    DECLARE_INJECT_METHOD(void, Inject, SettingsViewController* settingsViewController);
)