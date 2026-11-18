// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a1e20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a1e20 LeafForward7a1e20::Forward
#include "LeafForward7a1e20.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a1e20::Forward() { return leaf_target(this); }
