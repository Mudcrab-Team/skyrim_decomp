// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf04460, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf04460 LeafForwardf04460::Forward
#include "LeafForwardf04460.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf04460::Forward() { return leaf_target(this); }
