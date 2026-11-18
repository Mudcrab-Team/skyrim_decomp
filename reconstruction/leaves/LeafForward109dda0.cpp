// Source exposure: binary-analysis; no external implementation reused.
// LeafForward109dda0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x109dda0 LeafForward109dda0::Forward
#include "LeafForward109dda0.h"
extern "C" void* leaf_target(void*);
void* LeafForward109dda0::Forward() { return leaf_target(this); }
