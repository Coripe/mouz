#include "pid.h"

pid_t motorA, motorB;
pid_t turn;
pid_t trace_pid;

void pid_cal(pid_t *pid)
{
    float integral_candidate;
    float output_candidate;

    pid->error[0] = pid->target - pid->now;

    if(pid->pid_mode == DELTA_PID)
    {
        pid->pout = pid->p * (pid->error[0] - pid->error[1]);
        pid->iout = pid->i * pid->error[0];
        pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
        pid->out += pid->pout + pid->iout + pid->dout;
    }
    else if(pid->pid_mode == POSITION_PID)
    {
        pid->pout = pid->p * pid->error[0];
        pid->dout = pid->d * (pid->error[0] - pid->error[1]);

        integral_candidate = pid->iout + pid->i * pid->error[0];
        if(integral_candidate > pid->integral_limit)
            integral_candidate = pid->integral_limit;
        else if(integral_candidate < -pid->integral_limit)
            integral_candidate = -pid->integral_limit;

        output_candidate = pid->pout + integral_candidate + pid->dout;
        if(!((output_candidate > pid->output_limit && pid->error[0] > 0.0f) ||
             (output_candidate < -pid->output_limit && pid->error[0] < 0.0f)))
        {
            pid->iout = integral_candidate;
        }

        pid->out = pid->pout + pid->iout + pid->dout;
    }

    if(pid->out > pid->output_limit)
        pid->out = pid->output_limit;
    else if(pid->out < -pid->output_limit)
        pid->out = -pid->output_limit;

    pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];
}

void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d)
{
    pid->pid_mode = mode;
    pid->p = p;
    pid->i = i;
    pid->d = d;
    pid->integral_limit = 5000.0f;
    pid->output_limit = 5000.0f;
    pid_reset(pid);
}

void pid_reset(pid_t *pid)
{
    pid->target = 0.0f;
    pid->now = 0.0f;
    pid->error[0] = 0.0f;
    pid->error[1] = 0.0f;
    pid->error[2] = 0.0f;
    pid->pout = 0.0f;
    pid->iout = 0.0f;
    pid->dout = 0.0f;
    pid->out = 0.0f;
}

void pid_set_limits(pid_t *pid, float integral_limit, float output_limit)
{
    pid->integral_limit = integral_limit;
    pid->output_limit = output_limit;
}

void pidout_limit(pid_t *pid)
{
    if(pid->out > pid->output_limit)
        pid->out = pid->output_limit;
    else if(pid->out < -pid->output_limit)
        pid->out = -pid->output_limit;
}
