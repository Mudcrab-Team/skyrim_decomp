// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5ad140, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5ad140 LeafForward5ad140::Forward
#include "LeafForward5ad140.h"
extern "C" void* leaf_target(void*);
void* LeafForward5ad140::Forward() { return leaf_target(this); }
