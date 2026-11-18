// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5449f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5449f0 LeafForward5449f0::Forward
#include "LeafForward5449f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5449f0::Forward() { return leaf_target(this); }
