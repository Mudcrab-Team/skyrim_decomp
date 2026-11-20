// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfafcc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfafcc0 LeafForwardfafcc0::Forward
#include "LeafForwardfafcc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfafcc0::Forward() { return leaf_target(this); }
