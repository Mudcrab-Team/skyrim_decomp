// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfab0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfab0 LeafForwardfdfab0::Forward
#include "LeafForwardfdfab0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfab0::Forward() { return leaf_target(this); }
