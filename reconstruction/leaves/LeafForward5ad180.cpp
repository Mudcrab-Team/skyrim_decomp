// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5ad180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5ad180 LeafForward5ad180::Forward
#include "LeafForward5ad180.h"
extern "C" void* leaf_target(void*);
void* LeafForward5ad180::Forward() { return leaf_target(this); }
