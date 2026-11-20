// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1303d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1303d40 LeafForward1303d40::Forward
#include "LeafForward1303d40.h"
extern "C" void* leaf_target(void*);
void* LeafForward1303d40::Forward() { return leaf_target(this); }
