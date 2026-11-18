// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7390 LeafForwardfb7390::Forward
#include "LeafForwardfb7390.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7390::Forward() { return leaf_target(this); }
