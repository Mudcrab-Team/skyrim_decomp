// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ebc00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ebc00 LeafForward8ebc00::Forward
#include "LeafForward8ebc00.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ebc00::Forward() { return leaf_target(this); }
