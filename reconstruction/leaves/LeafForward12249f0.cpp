// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12249f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12249f0 LeafForward12249f0::Forward
#include "LeafForward12249f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward12249f0::Forward() { return leaf_target(this); }
