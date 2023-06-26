#include "Installers/MenuInstaller.hpp"
#include "UI/Manager.hpp"
#include "UI/ViewControllers/SongPlayerViewController.hpp"
#include "UI/ScreenController.hpp"

#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"
#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/ScopeConcreteIdArgConditionCopyNonLazyBinder.hpp"

DEFINE_TYPE(MenuMusicPlayer::Installers, MenuInstaller);

using namespace Lapiz::Zenject::ZenjectExtensions;

void MenuMusicPlayer::Installers::MenuInstaller::InstallBindings()
{
    auto container = get_Container();
    
    FromNewComponentAsViewController(container->Bind<SettingsViewController*>())->AsSingle();
    FromNewComponentOnNewGameObject(container->BindInterfacesAndSelfTo<SettingsFlowCoordinator*>())->AsSingle();

    container->BindInterfacesAndSelfTo<PauseInputController*>()->AsSingle();

    container->BindInterfacesAndSelfTo<UIManager*>()->AsSingle();

    container->BindInterfacesAndSelfTo<ScreenController*>()->AsSingle();
    FromNewComponentAsViewController(container->BindInterfacesAndSelfTo<SongPlayerViewController*>())->AsSingle();
    FromNewComponentOnNewGameObject(container->BindInterfacesAndSelfTo<PlaybackController*>())->AsSingle();
}