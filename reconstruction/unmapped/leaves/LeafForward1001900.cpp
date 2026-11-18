// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1001900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1001900 LeafForward1001900::Forward
#include "LeafForward1001900.h"
extern "C" void* leaf_target(void*);
void* LeafForward1001900::Forward() { return leaf_target(this); }
