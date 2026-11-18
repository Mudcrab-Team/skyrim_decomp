// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf746a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf746a0 LeafForwardf746a0::Forward
#include "LeafForwardf746a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf746a0::Forward() { return leaf_target(this); }
