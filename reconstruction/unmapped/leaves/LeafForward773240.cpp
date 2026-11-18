// Source exposure: binary-analysis; no external implementation reused.
// LeafForward773240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x773240 LeafForward773240::Forward
#include "LeafForward773240.h"
extern "C" void* leaf_target(void*);
void* LeafForward773240::Forward() { return leaf_target(this); }
