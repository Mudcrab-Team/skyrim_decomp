// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1001fb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1001fb0 LeafForward1001fb0::Forward
#include "LeafForward1001fb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1001fb0::Forward() { return leaf_target(this); }
