// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76080 LeafForwardf76080::Forward
#include "LeafForwardf76080.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76080::Forward() { return leaf_target(this); }
