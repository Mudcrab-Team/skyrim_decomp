// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7370 LeafForwardfb7370::Forward
#include "LeafForwardfb7370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7370::Forward() { return leaf_target(this); }
