// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9e540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9e540 LeafForwardf9e540::Forward
#include "LeafForwardf9e540.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9e540::Forward() { return leaf_target(this); }
