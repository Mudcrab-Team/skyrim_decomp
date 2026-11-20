// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7800 LeafForwardfb7800::Forward
#include "LeafForwardfb7800.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7800::Forward() { return leaf_target(this); }
