// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf67e90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf67e90 LeafForwardf67e90::Forward
#include "LeafForwardf67e90.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf67e90::Forward() { return leaf_target(this); }
