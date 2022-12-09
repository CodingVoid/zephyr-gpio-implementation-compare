#include "common.h"

const struct gpio_dt_spec GPIO_POWER = GPIO_DT_SPEC_GET(DT_NODELABEL(power), gpios);
const struct gpio_dt_spec GPIO_OTHER = GPIO_DT_SPEC_GET(DT_NODELABEL(other), gpios);
int do_power()
{
	gpio_pin_set_dt(PIN_POWER, 1);
	gpio_pin_get_dt(PIN_OTHER);
}

extern struct gpio_config gpio_configs[];

void gpio_init()
{
	for (int i = 0; i < sizeof(gpio_configs)/sizeof(struct gpio_dt_spec); i++) {
		struct gpio_config gpio_config = gpio_configs[i];
		struct gpio_dt_spec *gpio_spec = gpio_config.gpio_spec;
		int ret = gpio_pin_configure_dt(gpio_spec, gpio_config.flags);
	}
}

int main()
{
	gpio_init();
	//Do whatever other stuff
	do_power();
}
