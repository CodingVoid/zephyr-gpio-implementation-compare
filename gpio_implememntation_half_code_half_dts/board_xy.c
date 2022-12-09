#include "common.h"

const struct gpio_config gpio_configs[] = {
	{ DEVICE_DT_GET(DT_NODELABEL(power)), GPIO_OUTPUT },
	{ DEVICE_DT_GET(DT_NODELABEL(other)), GPIO_INPUT },
	// probably a few more
};
