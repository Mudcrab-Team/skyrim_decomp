// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8a5250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8a5250 LeafForward8a5250::Forward
#include "LeafForward8a5250.h"
extern "C" void* leaf_target(void*);
void* LeafForward8a5250::Forward() { return leaf_target(this); }
