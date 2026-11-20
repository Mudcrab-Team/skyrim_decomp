// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5ad130, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5ad130 LeafForward5ad130::Forward
#include "LeafForward5ad130.h"
extern "C" void* leaf_target(void*);
void* LeafForward5ad130::Forward() { return leaf_target(this); }
