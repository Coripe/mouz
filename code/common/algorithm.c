#include"algorithm.h"
#include"zf_common_headfile.h"

/*
 * state是上一次滤波的结果 in是输入的数据
 */
void lpf_general(void *state, const void *in, float alpha, alg_type type)
{
    float *s = (float *)state;

    if(alpha < 0.0f)      alpha = 0.0f;
    else if(alpha > 1.0f) alpha = 1.0f;

    if(type == alg_float)
    {
        *s = alpha * (*(const float *)in) + (1.0f - alpha) * (*s);
    }
    else if(type == alg_int)
    {
        *s = alpha * (float)(*(const int *)in) + (1.0f - alpha) * (*s);
    }
    else
    {
        zf_assert(FALSE);
    }
}

/*
 *
 */

void limit_general(void *val, void *min, void *max, alg_type type)
{
    if(type == alg_float)
    {
        float *v = (float *)val;
        float mi = *(float *)min;
        float ma = *(float *)max;
        if(*v > ma)
            *v = ma;
        else if(*v < mi)
            *v = mi;
    }
    else if(type == alg_int)
    {
        int *v = (int *)val;
        int mi = *(int *)min;
        int ma = *(int *)max;
        if(*v > ma)
            *v = ma;
        else if(*v < mi)
            *v = mi;
    }
}
