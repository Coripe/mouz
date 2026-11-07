#include"zf_common_headfile.h"
#include"encoder.h"
#include"stdlib.h"



#define encoder_max_diffrent          (300)
#define filtered_alpha                (0.2f)

volatile encoder_t encoder_data;


void encoder_init()
{
    encoder_dir_init(ENCODER_1,ENCODER_1_A,ENCODER_1_B);
    encoder_dir_init(ENCODER_2,ENCODER_2_A,ENCODER_2_B);
}


void encoder_cal_cnt()
{

    int raw_l,raw_r;
    static int last_raw_l = 0;
    static int last_raw_r = 0;
    raw_l = (int)encoder_get_count(ENCODER_1);
    raw_r = (int)encoder_get_count(ENCODER_2);

    if(abs(raw_l - last_raw_l) >= encoder_max_diffrent)
    {
        raw_l = last_raw_l;
    }
    else
    {
        last_raw_l = raw_l;
    }

    if(abs(raw_r - last_raw_r) >= encoder_max_diffrent)
    {
        raw_r = last_raw_r;
    }
    else
    {
        last_raw_r = raw_r;
    }

    encoder_data.encoder_l = raw_l;
    encoder_data.encoder_r = raw_r;
}

int encoder_get_data(encoder_dir dir)
{
    if(dir == left)
    {
        return encoder_data.encoder_l;
    }
    else
    {
        return encoder_data.encoder_r;
    }
}

void encoder_cal_speed()
{
    float Ts = 0.002f;
    int PPR = 1024;
    int now_l,now_r;
    static int last_l = 0,last_r = 0;
    int error_l,error_r;
    float speed_raw_l,speed_raw_r;

    static float filtered_l = 0;
    static float filtered_r = 0;


    now_l = encoder_get_data(left);
    error_l = now_l - last_l;
    last_l = now_l;

    now_r = encoder_get_data(right);
    error_r = now_r - last_r;
    last_r = now_r;

    speed_raw_l = (error_l * 60.0f) / (PPR * Ts);
    speed_raw_r = (error_r * 60.0f) / (PPR * Ts);

    filtered_l = filtered_alpha * speed_raw_l + (1.0f - filtered_alpha) * filtered_l;
    filtered_r = filtered_alpha * speed_raw_r + (1.0f - filtered_alpha) * filtered_r;

    encoder_data.speed_l = filtered_l;
    encoder_data.speed_r = filtered_r;
}

float encoder_get_speed(encoder_dir dir)
{
    if(dir == left)
    {
        return encoder_data.speed_l;
    }
    else
    {
        return encoder_data.speed_r;
    }
}

