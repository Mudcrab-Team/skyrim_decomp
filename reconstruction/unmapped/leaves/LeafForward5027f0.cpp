// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5027f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5027f0 LeafForward5027f0::Forward
#include "LeafForward5027f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5027f0::Forward() { return leaf_target(this); }
