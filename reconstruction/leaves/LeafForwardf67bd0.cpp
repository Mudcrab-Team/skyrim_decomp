// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf67bd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf67bd0 LeafForwardf67bd0::Forward
#include "LeafForwardf67bd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf67bd0::Forward() { return leaf_target(this); }
