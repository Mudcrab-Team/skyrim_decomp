// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2d1c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2d1c10 LeafForward2d1c10::Forward
#include "LeafForward2d1c10.h"
extern "C" void* leaf_target(void*);
void* LeafForward2d1c10::Forward() { return leaf_target(this); }
