#include "common.h"

#define GPIO_POWER MCHP_GPIO_0000_ID

struct device* pin2portdev_lookup_table[] = {
	DEVICE_DT_GET(DT_NODELABEL(port_xy)),
	DEVICE_DT_GET(DT_NODELABEL(port_xz)),
	// 200 more of these...
};
// one could merge them both together
const struct gpio_config gpio_configs[] = {
	{DEVICE_DT_GET(DT_NODELABEL(port_xy)), GPIO_POWER, GPIO_OUTPUT},
	{DEVICE_DT_GET(DT_NODELABEL(port_xz)), GPIO_OTHER, GPIO_INPUT},
	// 200 more of these...
};
