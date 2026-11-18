// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardffb850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xffb850 LeafForwardffb850::Forward
#include "LeafForwardffb850.h"
extern "C" void* leaf_target(void*);
void* LeafForwardffb850::Forward() { return leaf_target(this); }
