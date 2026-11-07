#include"zf_common_headfile.h"
#include"init.h"


void buzzer_init()
{
    gpio_init(BUZZER_PIN,GPO,0,GPO_PUSH_PULL);
}

void buzzer_on()
{
    gpio_set_level(BUZZER_PIN,1);
}

void buzzer_off()
{
    gpio_set_level(BUZZER_PIN,0);
}

void led_init()
{
    gpio_init(LED_PIN,GPO,0,GPO_PUSH_PULL);
}

void led_on()
{
    gpio_set_level(LED_PIN,1);
}

void led_off()
{
    gpio_set_level(LED_PIN,0);
}


//≥ı ºªØ
void init_all()
{
    buzzer_init();
    encoder_init();
}

void run()
{

}

void run_test()
{

}
