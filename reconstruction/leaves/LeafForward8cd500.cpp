// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8cd500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8cd500 LeafForward8cd500::Forward
#include "LeafForward8cd500.h"
extern "C" void* leaf_target(void*);
void* LeafForward8cd500::Forward() { return leaf_target(this); }
