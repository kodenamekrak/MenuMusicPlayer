#include "main.hpp"
#include "UI/ViewControllers/SettingsViewController.hpp"
#include "assets.hpp"

#include "bsml/shared/BSML.hpp"

DEFINE_TYPE(MenuMusicPlayer, SettingsViewController);

namespace MenuMusicPlayer {

    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if(!firstActivation)
            return;
        BSML::parse_and_construct(IncludedAssets::SettingsViewController_bsml, get_transform(), this);
    }

    void SettingsViewController::RoundRotation()
    {
        int rot = getModConfig().rotation.GetValue() * 10;
        float newRotation = rot / 10.0f;
        set_rotationFloat(newRotation);
        rotationSlider->set_Value(newRotation);
    }

    void SettingsViewController::RoundHeight()
    {
        int height = getModConfig().height.GetValue() * 10;
        float newHeight = height / 10.0f;
        set_heightFloat(newHeight);
        heightSlider->set_Value(newHeight);
    }

    bool SettingsViewController::get_enabledBool() { return getModConfig().enabled.GetValue(); }
    void SettingsViewController::set_enabledBool(bool value)
    {
        getModConfig().enabled.SetValue(value, true);
        enabledDidChangeEvent.invoke(value);
    }

    bool SettingsViewController::get_autoplayBool() { return getModConfig().autoplay.GetValue(); }
    void SettingsViewController::set_autoplayBool(bool value) { getModConfig().autoplay.SetValue(value, true); }

    float SettingsViewController::get_rotationFloat() { return getModConfig().rotation.GetValue(); }
    void SettingsViewController::set_rotationFloat(float value)
    {
        getModConfig().rotation.SetValue(value, true);
        rotationDidChangeEvent.invoke(value);
    }

    float SettingsViewController::get_heightFloat() { return getModConfig().height.GetValue(); }
    void SettingsViewController::set_heightFloat(float value)
    {
        getModConfig().height.SetValue(value, true);
        heightDidChangeEvent.invoke(value);
    }
}