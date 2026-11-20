// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1002000, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1002000 LeafForward1002000::Forward
#include "LeafForward1002000.h"
extern "C" void* leaf_target(void*);
void* LeafForward1002000::Forward() { return leaf_target(this); }
