// Source exposure: binary-analysis; no external implementation reused.
// LeafForward891ca0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x891ca0 LeafForward891ca0::Forward
#include "LeafForward891ca0.h"
extern "C" void* leaf_target(void*);
void* LeafForward891ca0::Forward() { return leaf_target(this); }
