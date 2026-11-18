// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1100 LeafForwardfb1100::Forward
#include "LeafForwardfb1100.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1100::Forward() { return leaf_target(this); }
