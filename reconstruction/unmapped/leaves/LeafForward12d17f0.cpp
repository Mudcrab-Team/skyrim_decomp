// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12d17f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12d17f0 LeafForward12d17f0::Forward
#include "LeafForward12d17f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward12d17f0::Forward() { return leaf_target(this); }
