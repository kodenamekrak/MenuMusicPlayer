#pragma once

#include "custom-types/shared/macros.hpp"

#include "ViewControllers/SongPlayerViewController.hpp"
#include "ViewControllers/SettingsViewController.hpp"

#include "Zenject/IInitializable.hpp"

#include "System/IDisposable.hpp"

#include "bsml/shared//BSML/FloatingScreen/FloatingScreen.hpp"

#define INTERFACES { classof(Zenject::IInitializable*), classof(System::IDisposable*) }

___DECLARE_TYPE_WRAPPER_INHERITANCE(MenuMusicPlayer, ScreenController, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, Il2CppObject, "MenuMusicPlayer", INTERFACES, 0, nullptr,

    DECLARE_INSTANCE_FIELD_PRIVATE(BSML::FloatingScreen*, _songPlayerFloatingScreen);
    DECLARE_INSTANCE_FIELD_PRIVATE(SongPlayerViewController*, _songPlayerViewController);
    DECLARE_INSTANCE_FIELD_PRIVATE(SettingsViewController*, _settingsViewController);
    DECLARE_INSTANCE_FIELD(float, lastRotation);

    DECLARE_OVERRIDE_METHOD(void, Initialize, il2cpp_utils::il2cpp_type_check::MetadataGetter<&Zenject::IInitializable::Initialize>::get());
    DECLARE_OVERRIDE_METHOD(void, Dispose, il2cpp_utils::il2cpp_type_check::MetadataGetter<&System::IDisposable::Dispose>::get());

    DECLARE_INSTANCE_METHOD(void, SetScreenActive, bool active);
    DECLARE_INSTANCE_METHOD(void, SetScreenRotation, float angle);
    DECLARE_INSTANCE_METHOD(void, SetScreenHeight, float height);

    DECLARE_CTOR(ctor, SongPlayerViewController* songPlayerViewController, SettingsViewController* settingsViewController);
)