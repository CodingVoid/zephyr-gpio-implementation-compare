#include "common.h"
#include "board.h" // one would also need to adjust the build system in order to always get the correct header file corresponding to the board that is currently built for
#include <MEC1501hsz.h> // That one is from the Microchip git submodule

extern struct device* pin2portdev_lookup_table[];
void gpio_set_wrapper(int gpio_pin, int value)
{
	struct device *port_dev = pin2portdev_lookup_table[gpio_pin];
	int pin = gpio_pin & 0x1F;
	gpio_pin_set_raw(port_dev, pin, value);
}

int do_power()
{
	gpio_set_wrapper(GPIO_POWER, 1);
}

extern struct gpio_config gpio_configs[];
void gpio_init()
{
	for (int i = 0; i < ARRAY_SIZE(gpio_configs); i++) {
		struct gpio_config gc = gpio_configs[i];
		int ret = gpio_pin_configure(gc.port, gc.pin, gc.flags);
	}
}

int main()
{
	gpio_init();
	//Do whatever other stuff
	do_power();
}
