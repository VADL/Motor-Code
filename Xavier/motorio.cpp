extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}


#include <stdio.h>
#include <iostream>
#include <time.h>

#define inhibit_pin  113 //P9_28
#define cur_monitor_pin  4 //P9_33 (ADC 4)
#define LED_pin  15 //P9_24

int main(int argc, char *argv[])
{
	rc_initialize();
	int freq = 15*1000;
        rc_set_pinmux_mode(3,PINMUX_PWM);
        rc_pwm_init(0,freq);
        rc_pwm_set_duty(0,'B', 0.0);

	rc_set_pinmux_mode(inhibit_pin, PINMUX_GPIO);
	rc_set_pinmux_mode(LED_pin, PINMUX_GPIO);
	rc_gpio_export(inhibit_pin);
	rc_gpio_export(LED_pin);
	rc_gpio_set_dir(inhibit_pin, OUTPUT_PIN);
	rc_gpio_set_dir(LED_pin, OUTPUT_PIN);

	int entry = 0;
	while(entry != -1){
		float cur_monitor_val = rc_adc_volt(cur_monitor_pin);
		printf("\nEnter a value 0/1 for LED: ");
		scanf("%i", &entry);
		rc_gpio_set_value(LED_pin, entry);

		printf("\nEnter a value 0/1 for inhibit: ");
		scanf("%i", &entry);
		rc_gpio_set_value(inhibit_pin, entry);

		printf("\nCurrent Monitor Value: %i", cur_monitor_val);
		fflush(stdin);
	}
	
	return 0;
}