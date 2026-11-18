// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7aacf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7aacf0 LeafForward7aacf0::Forward
#include "LeafForward7aacf0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7aacf0::Forward() { return leaf_target(this); }
