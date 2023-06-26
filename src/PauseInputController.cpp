#include "main.hpp"
#include "PauseInputController.hpp"

DEFINE_TYPE(MenuMusicPlayer, PauseInputController);

namespace MenuMusicPlayer {

    void PauseInputController::Inject(GlobalNamespace::VRControllersInputManager* vrControllersInputManager)
    {
        _vrControllersInputManager = vrControllersInputManager;

    }

    void PauseInputController::Tick()
    {
        bool pressed = _vrControllersInputManager->MenuButtonDown();
        if(pressed && !pressedLastFrame)
        {
            menuButtonTriggeredEvent.invoke();
        }
        pressedLastFrame = pressed;
    }
}