// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1289150, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1289150 LeafForward1289150::Forward
#include "LeafForward1289150.h"
extern "C" void* leaf_target(void*);
void* LeafForward1289150::Forward() { return leaf_target(this); }
