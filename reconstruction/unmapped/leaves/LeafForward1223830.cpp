// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1223830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1223830 LeafForward1223830::Forward
#include "LeafForward1223830.h"
extern "C" void* leaf_target(void*);
void* LeafForward1223830::Forward() { return leaf_target(this); }
