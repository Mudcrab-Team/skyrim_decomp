// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5ad120, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5ad120 LeafForward5ad120::Forward
#include "LeafForward5ad120.h"
extern "C" void* leaf_target(void*);
void* LeafForward5ad120::Forward() { return leaf_target(this); }
