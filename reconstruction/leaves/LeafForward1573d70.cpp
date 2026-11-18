// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1573d70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1573d70 LeafForward1573d70::Forward
#include "LeafForward1573d70.h"
extern "C" void* leaf_target(void*);
void* LeafForward1573d70::Forward() { return leaf_target(this); }
