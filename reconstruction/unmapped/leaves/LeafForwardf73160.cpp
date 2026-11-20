// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73160 LeafForwardf73160::Forward
#include "LeafForwardf73160.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73160::Forward() { return leaf_target(this); }
