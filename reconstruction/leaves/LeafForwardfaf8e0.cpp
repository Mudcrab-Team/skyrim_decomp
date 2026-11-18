// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf8e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf8e0 LeafForwardfaf8e0::Forward
#include "LeafForwardfaf8e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf8e0::Forward() { return leaf_target(this); }
