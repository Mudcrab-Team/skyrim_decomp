// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb20c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb20c0 LeafForwardfb20c0::Forward
#include "LeafForwardfb20c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb20c0::Forward() { return leaf_target(this); }
