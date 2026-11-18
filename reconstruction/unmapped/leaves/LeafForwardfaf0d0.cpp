// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf0d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf0d0 LeafForwardfaf0d0::Forward
#include "LeafForwardfaf0d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf0d0::Forward() { return leaf_target(this); }
