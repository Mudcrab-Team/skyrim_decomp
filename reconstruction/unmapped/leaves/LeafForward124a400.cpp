// Source exposure: binary-analysis; no external implementation reused.
// LeafForward124a400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x124a400 LeafForward124a400::Forward
#include "LeafForward124a400.h"
extern "C" void* leaf_target(void*);
void* LeafForward124a400::Forward() { return leaf_target(this); }
