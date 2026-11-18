// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf19460, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf19460 LeafForwardf19460::Forward
#include "LeafForwardf19460.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf19460::Forward() { return leaf_target(this); }
