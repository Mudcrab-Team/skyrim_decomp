// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1336b70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1336b70 LeafForward1336b70::Forward
#include "LeafForward1336b70.h"
extern "C" void* leaf_target(void*);
void* LeafForward1336b70::Forward() { return leaf_target(this); }
