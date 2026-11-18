// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb0100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb0100 LeafForwardfb0100::Forward
#include "LeafForwardfb0100.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb0100::Forward() { return leaf_target(this); }
