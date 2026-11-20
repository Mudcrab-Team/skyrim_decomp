// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69080 LeafForwardf69080::Forward
#include "LeafForwardf69080.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69080::Forward() { return leaf_target(this); }
