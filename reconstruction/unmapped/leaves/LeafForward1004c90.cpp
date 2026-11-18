// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1004c90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1004c90 LeafForward1004c90::Forward
#include "LeafForward1004c90.h"
extern "C" void* leaf_target(void*);
void* LeafForward1004c90::Forward() { return leaf_target(this); }
