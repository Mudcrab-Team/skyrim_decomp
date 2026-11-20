// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76630 LeafForwardf76630::Forward
#include "LeafForwardf76630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76630::Forward() { return leaf_target(this); }
