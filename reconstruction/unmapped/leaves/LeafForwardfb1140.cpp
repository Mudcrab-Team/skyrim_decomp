// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1140, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1140 LeafForwardfb1140::Forward
#include "LeafForwardfb1140.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1140::Forward() { return leaf_target(this); }
