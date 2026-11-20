// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8c0260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8c0260 LeafForward8c0260::Forward
#include "LeafForward8c0260.h"
extern "C" void* leaf_target(void*);
void* LeafForward8c0260::Forward() { return leaf_target(this); }
