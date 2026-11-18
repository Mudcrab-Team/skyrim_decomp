// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8c080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8c080 LeafForwardf8c080::Forward
#include "LeafForwardf8c080.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8c080::Forward() { return leaf_target(this); }
