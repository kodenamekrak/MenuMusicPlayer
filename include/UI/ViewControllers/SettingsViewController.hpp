#pragma once

#include "custom-types/shared/macros.hpp"

#include "bsml/shared/macros.hpp"

#include "HMUI/ViewController.hpp"

#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"

DECLARE_CLASS_CODEGEN(MenuMusicPlayer, SettingsViewController, HMUI::ViewController,

    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, rotationSlider);
    DECLARE_INSTANCE_FIELD(BSML::SliderSetting*, heightSlider);

    public:

    UnorderedEventCallback<bool> enabledDidChangeEvent;
    UnorderedEventCallback<float> rotationDidChangeEvent;
    UnorderedEventCallback<float> heightDidChangeEvent;

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::ViewController::DidActivate>::get(), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_METHOD(void, RoundRotation);
    DECLARE_INSTANCE_METHOD(void, RoundHeight);

    DECLARE_BSML_PROPERTY(bool, enabledBool);
    DECLARE_BSML_PROPERTY(bool, autoplayBool);
    DECLARE_BSML_PROPERTY(float, rotationFloat);
    DECLARE_BSML_PROPERTY(float, heightFloat);

    DECLARE_DEFAULT_CTOR();
)