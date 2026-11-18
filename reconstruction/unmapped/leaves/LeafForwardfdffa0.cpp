// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdffa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdffa0 LeafForwardfdffa0::Forward
#include "LeafForwardfdffa0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdffa0::Forward() { return leaf_target(this); }
