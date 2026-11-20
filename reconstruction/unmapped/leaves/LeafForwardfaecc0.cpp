// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaecc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaecc0 LeafForwardfaecc0::Forward
#include "LeafForwardfaecc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaecc0::Forward() { return leaf_target(this); }
