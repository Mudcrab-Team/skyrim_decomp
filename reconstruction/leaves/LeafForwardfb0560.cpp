// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb0560, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb0560 LeafForwardfb0560::Forward
#include "LeafForwardfb0560.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb0560::Forward() { return leaf_target(this); }
