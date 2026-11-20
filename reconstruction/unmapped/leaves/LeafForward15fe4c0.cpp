// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15fe4c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15fe4c0 LeafForward15fe4c0::Forward
#include "LeafForward15fe4c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward15fe4c0::Forward() { return leaf_target(this); }
