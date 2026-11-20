// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1499730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1499730 LeafForward1499730::Forward
#include "LeafForward1499730.h"
extern "C" void* leaf_target(void*);
void* LeafForward1499730::Forward() { return leaf_target(this); }
