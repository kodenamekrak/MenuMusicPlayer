#include "main.hpp"
#include "UI/Manager.hpp"

#include "HMUI/ViewController_AnimationType.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"

#include "bsml/shared/BSML.hpp"

DEFINE_TYPE(MenuMusicPlayer, UIManager);

namespace MenuMusicPlayer {

    void UIManager::ctor(GlobalNamespace::MainFlowCoordinator* mainFlowCoordinator, ScreenController* screenController, SettingsFlowCoordinator* settingsFlowCoordinator)
    {
        getLogger().info("Ctor");
        _mainFlowCoordinator = mainFlowCoordinator;
        _screenController = screenController;
        _settingsFlowCoordinator = settingsFlowCoordinator;
        _menuButton = BSML::MenuButton::Make_new("MenuMusicPlayer", "MenuMusicPlayer Mod Settings", std::bind(&UIManager::PresentSettingsFlowCoordinator, this));
    }

    void UIManager::Initialize()
    {
        getLogger().info("Initialize");

        BSML::Register::RegisterMenuButton(_menuButton);
    }

    void UIManager::PresentSettingsFlowCoordinator()
    {
        _mainFlowCoordinator->YoungestChildFlowCoordinatorOrSelf()->PresentFlowCoordinator(_settingsFlowCoordinator, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
    }

    

    void UIManager::Dispose()
    {
        BSML::Register::UnRegisterMenuButton(_menuButton);
    }
}