// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122bec0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122bec0 LeafForward122bec0::Forward
#include "LeafForward122bec0.h"
extern "C" void* leaf_target(void*);
void* LeafForward122bec0::Forward() { return leaf_target(this); }
