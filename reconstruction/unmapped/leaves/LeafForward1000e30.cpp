// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1000e30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1000e30 LeafForward1000e30::Forward
#include "LeafForward1000e30.h"
extern "C" void* leaf_target(void*);
void* LeafForward1000e30::Forward() { return leaf_target(this); }
