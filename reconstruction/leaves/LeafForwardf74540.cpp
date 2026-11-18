// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74540 LeafForwardf74540::Forward
#include "LeafForwardf74540.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74540::Forward() { return leaf_target(this); }
