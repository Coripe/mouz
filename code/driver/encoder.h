#ifndef __ENCODER_H_
#define __ENCODER_H_

#define ENCODER_1                   (TIM4_ENCODER)
#define ENCODER_1_A                 (TIM4_ENCODER_CH1_P02_8)
#define ENCODER_1_B                 (TIM4_ENCODER_CH2_P33_5)

#define ENCODER_2                   (TIM6_ENCODER)
#define ENCODER_2_A                 (TIM6_ENCODER_CH1_P20_3)
#define ENCODER_2_B                 (TIM6_ENCODER_CH2_P20_0)

typedef struct{
        int encoder_l;
        int encoder_r;
        float speed_l;
        float speed_r;

}encoder_t;

typedef enum{
    left,
    right
}encoder_dir;

void encoder_init(void);
void encoder_cal_cnt(void);
int encoder_get_data(encoder_dir dir);
void encoder_cal_speed(void);
float encoder_get_speed(encoder_dir dir);

#endif
