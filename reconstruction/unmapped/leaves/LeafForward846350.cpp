// Source exposure: binary-analysis; no external implementation reused.
// LeafForward846350, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x846350 LeafForward846350::Forward
#include "LeafForward846350.h"
extern "C" void* leaf_target(void*);
void* LeafForward846350::Forward() { return leaf_target(this); }
