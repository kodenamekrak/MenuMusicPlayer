#include "main.hpp"
#include "UI/SettingsFlowCoordinator.hpp"

#include "HMUI/ViewController_AnimationType.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"

DEFINE_TYPE(MenuMusicPlayer, SettingsFlowCoordinator);

namespace MenuMusicPlayer {

    void SettingsFlowCoordinator::Inject(SettingsViewController* settingsViewController)
    {
        _settingsViewController = settingsViewController;
    }

    void SettingsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if(!firstActivation)
            return;
        showBackButton = true;
        SetTitle("MenuMusicPlayer", HMUI::ViewController::AnimationType::In);
        ProvideInitialViewControllers(_settingsViewController, nullptr, nullptr, nullptr, nullptr);
    }

    void SettingsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController)
    {
        parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
    }
}