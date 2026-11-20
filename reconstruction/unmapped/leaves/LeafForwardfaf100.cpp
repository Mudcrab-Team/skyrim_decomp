// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf100 LeafForwardfaf100::Forward
#include "LeafForwardfaf100.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf100::Forward() { return leaf_target(this); }
