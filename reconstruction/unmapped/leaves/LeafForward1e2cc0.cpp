// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1e2cc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1e2cc0 LeafForward1e2cc0::Forward
#include "LeafForward1e2cc0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1e2cc0::Forward() { return leaf_target(this); }
