// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf12650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf12650 LeafForwardf12650::Forward
#include "LeafForwardf12650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf12650::Forward() { return leaf_target(this); }
