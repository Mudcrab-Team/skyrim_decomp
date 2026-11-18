// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfaf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfaf0 LeafForwardfdfaf0::Forward
#include "LeafForwardfdfaf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfaf0::Forward() { return leaf_target(this); }
