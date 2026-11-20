// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf8f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf8f0 LeafForwardfaf8f0::Forward
#include "LeafForwardfaf8f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf8f0::Forward() { return leaf_target(this); }
