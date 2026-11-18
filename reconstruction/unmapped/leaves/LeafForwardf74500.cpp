// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74500 LeafForwardf74500::Forward
#include "LeafForwardf74500.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74500::Forward() { return leaf_target(this); }
