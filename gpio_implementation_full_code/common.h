
struct gpio_config {
	struct device *port;
	int pin;
	int flags;
};

void gpio_init();
void gpio_set_wrapper(int gpio_pin, int value);
// wrapper for any kind of gpio function, since zephyr GPIO API cannot be used directly
