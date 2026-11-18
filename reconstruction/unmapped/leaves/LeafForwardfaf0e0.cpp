// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf0e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf0e0 LeafForwardfaf0e0::Forward
#include "LeafForwardfaf0e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf0e0::Forward() { return leaf_target(this); }
