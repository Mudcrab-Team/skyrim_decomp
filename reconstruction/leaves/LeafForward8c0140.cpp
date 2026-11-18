// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8c0140, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8c0140 LeafForward8c0140::Forward
#include "LeafForward8c0140.h"
extern "C" void* leaf_target(void*);
void* LeafForward8c0140::Forward() { return leaf_target(this); }
