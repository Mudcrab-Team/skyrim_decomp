// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1005030, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1005030 LeafForward1005030::Forward
#include "LeafForward1005030.h"
extern "C" void* leaf_target(void*);
void* LeafForward1005030::Forward() { return leaf_target(this); }
