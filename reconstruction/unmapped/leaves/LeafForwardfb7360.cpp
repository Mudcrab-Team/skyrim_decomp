// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7360, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7360 LeafForwardfb7360::Forward
#include "LeafForwardfb7360.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7360::Forward() { return leaf_target(this); }
