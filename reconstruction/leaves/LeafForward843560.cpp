// Source exposure: binary-analysis; no external implementation reused.
// LeafForward843560, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x843560 LeafForward843560::Forward
#include "LeafForward843560.h"
extern "C" void* leaf_target(void*);
void* LeafForward843560::Forward() { return leaf_target(this); }
