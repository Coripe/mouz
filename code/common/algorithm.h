#ifndef __ALGORITHM_H_
#define __ALGORITHM_H_

//Ëã·¨»ã×Ü

typedef enum{
    alg_int,
    alg_float,

}alg_type;

void lpf_general(void *state, const void *in, float alpha, alg_type type);
void limit_general(void *in, void *min, void *max, alg_type type);


#endif
