#ifndef _PID_H_
#define _PID_H_
#include "zf_common_headfile.h"

enum
{
  POSITION_PID = 0,
  DELTA_PID,
};

typedef struct
{
    float target;
    float now;
    float error[3];
    float p,i,d;
    float pout, dout, iout;
    float out;
    float integral_limit;
    float output_limit;
    uint32_t pid_mode;
}pid_t;

void pid_cal(pid_t *pid);
void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d);
void pid_reset(pid_t *pid);
void pid_set_limits(pid_t *pid, float integral_limit, float output_limit);
void pidout_limit(pid_t *pid);

extern pid_t motorA;
extern pid_t motorB;
extern pid_t turn;
extern pid_t trace_pid;

#endif
