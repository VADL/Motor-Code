extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}


#include <stdio.h>

int main(int argc, char *argv[])
{
        rc_initialize();
        int freq = 15*1000;
        rc_set_pinmux_mode(3,PINMUX_PWM);
        rc_pwm_init(0,freq);
        float entry = 0.0;
        int encoder = 0;
        while(entry != -1.0){
                rc_pwm_set_duty(0,'B', entry);
                printf("Enter a decimal b/w 0 and 1: ");
                scanf("%f", &entry);
                printf("You entered: %f\n", entry);
                enc = rc_get_encoder_pos(3);
                printf("Enocoder value: %i\n", enc);
                fflush(stdin);
        }
        rc_pwm_close(0);
        return 0;
}


