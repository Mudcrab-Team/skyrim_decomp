// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1003980, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1003980 LeafForward1003980::Forward
#include "LeafForward1003980.h"
extern "C" void* leaf_target(void*);
void* LeafForward1003980::Forward() { return leaf_target(this); }
