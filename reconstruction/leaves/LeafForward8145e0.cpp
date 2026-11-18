// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8145e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8145e0 LeafForward8145e0::Forward
#include "LeafForward8145e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8145e0::Forward() { return leaf_target(this); }
