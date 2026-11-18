// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf67be0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf67be0 LeafForwardf67be0::Forward
#include "LeafForwardf67be0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf67be0::Forward() { return leaf_target(this); }
