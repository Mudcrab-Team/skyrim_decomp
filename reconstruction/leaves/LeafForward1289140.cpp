// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1289140, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1289140 LeafForward1289140::Forward
#include "LeafForward1289140.h"
extern "C" void* leaf_target(void*);
void* LeafForward1289140::Forward() { return leaf_target(this); }
