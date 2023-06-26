#include "main.hpp"
#include "UI/ScreenController.hpp"

#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(MenuMusicPlayer, ScreenController);

namespace MenuMusicPlayer {

    void ScreenController::ctor(SongPlayerViewController* songPlayerViewController, SettingsViewController* settingsViewController)
    {
        _songPlayerViewController = songPlayerViewController;
        _settingsViewController = settingsViewController;
    }

    void ScreenController::Initialize()
    {
        _songPlayerFloatingScreen = BSML::FloatingScreen::CreateFloatingScreen({100, 40}, false, {0, 3.2f, 4.3f}, {0, 0, 0}, 200, true);
        _songPlayerFloatingScreen->SetRootViewController(_songPlayerViewController, HMUI::ViewController::AnimationType::In);
        SetScreenRotation(getModConfig().rotation.GetValue());
        SetScreenHeight(getModConfig().height.GetValue());

        _settingsViewController->enabledDidChangeEvent += std::bind(&ScreenController::SetScreenActive, this, std::placeholders::_1);
        _settingsViewController->rotationDidChangeEvent += std::bind(&ScreenController::SetScreenRotation, this, std::placeholders::_1);
        _settingsViewController->heightDidChangeEvent += std::bind(&ScreenController::SetScreenHeight, this, std::placeholders::_1);
    }

    void ScreenController::SetScreenActive(bool active)
    {
        _songPlayerFloatingScreen->get_gameObject()->SetActive(active);
    }

    void ScreenController::SetScreenRotation(float angle)
    {
        _songPlayerFloatingScreen->get_transform()->RotateAround({0, 0, 0}, UnityEngine::Vector3::get_up(), -lastRotation);
        _songPlayerFloatingScreen->get_transform()->RotateAround({0, 0, 0}, UnityEngine::Vector3::get_up(), angle);
        lastRotation = angle;
    }

    void ScreenController::SetScreenHeight(float height)
    {
        UnityEngine::Vector3 position = _songPlayerFloatingScreen->get_ScreenPosition();
        position.y = 3.2f + height / 10.0f;
        _songPlayerFloatingScreen->set_ScreenPosition(position);
    }

    void ScreenController::Dispose()
    {
        _settingsViewController->enabledDidChangeEvent -= std::bind(&ScreenController::SetScreenActive, this, std::placeholders::_1);
        _settingsViewController->rotationDidChangeEvent -= std::bind(&ScreenController::SetScreenRotation, this, std::placeholders::_1);
        _settingsViewController->heightDidChangeEvent -= std::bind(&ScreenController::SetScreenHeight, this, std::placeholders::_1);
    }
}