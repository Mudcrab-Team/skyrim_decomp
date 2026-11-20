// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb2100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb2100 LeafForwardfb2100::Forward
#include "LeafForwardfb2100.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb2100::Forward() { return leaf_target(this); }
