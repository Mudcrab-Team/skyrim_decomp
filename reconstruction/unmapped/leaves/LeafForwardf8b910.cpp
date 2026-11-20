// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8b910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8b910 LeafForwardf8b910::Forward
#include "LeafForwardf8b910.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8b910::Forward() { return leaf_target(this); }
