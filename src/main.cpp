#include "main.hpp"
#include "Installers/MenuInstaller.hpp"
#include "Hooks/SongPreviewPlayer.hpp"

#include "lapiz/shared/zenject/Zenjector.hpp"

DEFINE_CONFIG(ModConfig);

static ModInfo modInfo;

Logger &getLogger()
{
    static Logger *logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo &info)
{
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;

    getModConfig().Init(modInfo);

    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load()
{
    il2cpp_functions::Init();

    getLogger().info("Installing MenuMusicPlayer...");

    auto zenjector = Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<MenuMusicPlayer::Installers::MenuInstaller*>(Lapiz::Zenject::Location::Menu);

    MenuMusicPlayer::Hooks::InstallPreviewPlayerHooks();

    getLogger().info("Installed MenuMusicPlayer!");
}