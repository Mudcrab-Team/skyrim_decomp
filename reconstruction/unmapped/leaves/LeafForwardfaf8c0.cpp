// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf8c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf8c0 LeafForwardfaf8c0::Forward
#include "LeafForwardfaf8c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf8c0::Forward() { return leaf_target(this); }
