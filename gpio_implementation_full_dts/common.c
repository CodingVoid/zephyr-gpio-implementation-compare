
#define GET_DT_SPEC(n) GPIO_DT_SPEC_GET(n, gpios)
const struct gpio_dt_spec gpio_configs[] = {
	DT_FOREACH_CHILD_SEP(DT_NODELABEL(gpios), GET_DT_SPEC, (,))
};

void gpio_init()
{
	for (int i = 0; i < sizeof(gpio_configs)/sizeof(struct gpio_dt_spec); i++) {
		struct gpio_dt_spec g = gpio_configs[i];
		int ret = gpio_pin_configure(g.port, g.pin, g.dt_flags);
	}
}

const struct gpio_dt_spec GPIO_POWER = GPIO_DT_SPEC_GET(DT_NODELABEL(power), gpios);
int do_power()
{
	gpio_pin_set_dt(PIN_POWER, 1);
}

int main()
{
	gpio_init();
	//Do whatever other stuff
	do_power();
}
