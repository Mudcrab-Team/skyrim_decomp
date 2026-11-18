// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10defa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10defa0 LeafForward10defa0::Forward
#include "LeafForward10defa0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10defa0::Forward() { return leaf_target(this); }
