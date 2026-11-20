// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14e8520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14e8520 LeafForward14e8520::Forward
#include "LeafForward14e8520.h"
extern "C" void* leaf_target(void*);
void* LeafForward14e8520::Forward() { return leaf_target(this); }
