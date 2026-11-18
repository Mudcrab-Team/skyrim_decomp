// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1573df0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1573df0 LeafForward1573df0::Forward
#include "LeafForward1573df0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1573df0::Forward() { return leaf_target(this); }
