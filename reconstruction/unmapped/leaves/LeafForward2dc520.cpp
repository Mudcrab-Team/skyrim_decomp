// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2dc520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2dc520 LeafForward2dc520::Forward
#include "LeafForward2dc520.h"
extern "C" void* leaf_target(void*);
void* LeafForward2dc520::Forward() { return leaf_target(this); }
