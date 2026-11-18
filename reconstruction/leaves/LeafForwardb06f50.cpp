// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb06f50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb06f50 LeafForwardb06f50::Forward
#include "LeafForwardb06f50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb06f50::Forward() { return leaf_target(this); }
