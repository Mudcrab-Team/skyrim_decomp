// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1ddf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1ddf0 LeafForwardf1ddf0::Forward
#include "LeafForwardf1ddf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1ddf0::Forward() { return leaf_target(this); }
