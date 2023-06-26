#pragma once

#include "custom-types/shared/macros.hpp"

#include "ScreenController.hpp"
#include "SettingsFlowCoordinator.hpp"

#include "Zenject/IInitializable.hpp"

#include "System/IDisposable.hpp"

#include "bsml/shared/BSML/MenuButtons/MenuButton.hpp"

#include "GlobalNamespace/MainFlowCoordinator.hpp"

#define INTERFACES { classof(Zenject::IInitializable*), classof(System::IDisposable*) }

___DECLARE_TYPE_WRAPPER_INHERITANCE(MenuMusicPlayer, UIManager, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, Il2CppObject, "MenuMusicPlayer", INTERFACES, 0, nullptr,

    DECLARE_INSTANCE_FIELD_PRIVATE(ScreenController*, _screenController);
    DECLARE_INSTANCE_FIELD_PRIVATE(SettingsFlowCoordinator*, _settingsFlowCoordinator);
    DECLARE_INSTANCE_FIELD_PRIVATE(GlobalNamespace::MainFlowCoordinator*, _mainFlowCoordinator);
    DECLARE_INSTANCE_FIELD_PRIVATE(BSML::MenuButton*, _menuButton);

    DECLARE_OVERRIDE_METHOD(void, Initialize, il2cpp_utils::il2cpp_type_check::MetadataGetter<&Zenject::IInitializable::Initialize>::get());
    DECLARE_OVERRIDE_METHOD(void, Dispose, il2cpp_utils::il2cpp_type_check::MetadataGetter<&System::IDisposable::Dispose>::get());

    DECLARE_INSTANCE_METHOD(void, PresentSettingsFlowCoordinator);

    DECLARE_CTOR(ctor, GlobalNamespace::MainFlowCoordinator* mainFlowCoordinator, ScreenController* screenController, SettingsFlowCoordinator* settingsFlowCoordinator);
)