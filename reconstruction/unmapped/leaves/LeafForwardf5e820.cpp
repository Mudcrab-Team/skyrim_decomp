// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5e820, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5e820 LeafForwardf5e820::Forward
#include "LeafForwardf5e820.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5e820::Forward() { return leaf_target(this); }
