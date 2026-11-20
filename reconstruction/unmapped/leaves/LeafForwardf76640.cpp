// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76640 LeafForwardf76640::Forward
#include "LeafForwardf76640.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76640::Forward() { return leaf_target(this); }
