// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5f820, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5f820 LeafForwardf5f820::Forward
#include "LeafForwardf5f820.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5f820::Forward() { return leaf_target(this); }
