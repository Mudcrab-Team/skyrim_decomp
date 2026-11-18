// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1289130, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1289130 LeafForward1289130::Forward
#include "LeafForward1289130.h"
extern "C" void* leaf_target(void*);
void* LeafForward1289130::Forward() { return leaf_target(this); }
