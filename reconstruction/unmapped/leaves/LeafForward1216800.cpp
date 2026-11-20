// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1216800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1216800 LeafForward1216800::Forward
#include "LeafForward1216800.h"
extern "C" void* leaf_target(void*);
void* LeafForward1216800::Forward() { return leaf_target(this); }
