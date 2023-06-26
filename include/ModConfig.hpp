#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(enabled, bool, "Enabled", true);
    CONFIG_VALUE(autoplay, bool, "Autoplay", false);
    CONFIG_VALUE(rotation, float, "Rotation", -55.0f);
    CONFIG_VALUE(height, float, "Height", -0.3f);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(enabled);
        CONFIG_INIT_VALUE(autoplay);
        CONFIG_INIT_VALUE(rotation);
        CONFIG_INIT_VALUE(height);
    )
)