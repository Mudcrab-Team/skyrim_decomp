// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8cce80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8cce80 LeafForward8cce80::Forward
#include "LeafForward8cce80.h"
extern "C" void* leaf_target(void*);
void* LeafForward8cce80::Forward() { return leaf_target(this); }
