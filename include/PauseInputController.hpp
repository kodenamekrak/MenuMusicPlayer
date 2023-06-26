#pragma once

#include "custom-types/shared/macros.hpp"

#include "lapiz/shared/macros.hpp"

#include "Zenject/ITickable.hpp"

#include "GlobalNamespace/VRControllersInputManager.hpp"

DECLARE_CLASS_CODEGEN_INTERFACES(MenuMusicPlayer, PauseInputController, Il2CppObject, classof(Zenject::ITickable*),

    DECLARE_INSTANCE_FIELD_PRIVATE(GlobalNamespace::VRControllersInputManager*, _vrControllersInputManager);
    DECLARE_INSTANCE_FIELD(bool, pressedLastFrame);

    UnorderedEventCallback<> menuButtonTriggeredEvent;

    DECLARE_OVERRIDE_METHOD(void, Tick, il2cpp_utils::il2cpp_type_check::MetadataGetter<&Zenject::ITickable::Tick>::get());
    DECLARE_INJECT_METHOD(void, Inject, GlobalNamespace::VRControllersInputManager* vrControllersInputManager);

    DECLARE_DEFAULT_CTOR();
)