// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf791f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf791f0 LeafForwardf791f0::Forward
#include "LeafForwardf791f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf791f0::Forward() { return leaf_target(this); }
