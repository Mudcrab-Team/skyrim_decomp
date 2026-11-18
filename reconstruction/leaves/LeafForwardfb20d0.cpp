// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb20d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb20d0 LeafForwardfb20d0::Forward
#include "LeafForwardfb20d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb20d0::Forward() { return leaf_target(this); }
