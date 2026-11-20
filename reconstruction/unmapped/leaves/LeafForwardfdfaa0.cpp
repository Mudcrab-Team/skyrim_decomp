// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfaa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfaa0 LeafForwardfdfaa0::Forward
#include "LeafForwardfdfaa0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfaa0::Forward() { return leaf_target(this); }
