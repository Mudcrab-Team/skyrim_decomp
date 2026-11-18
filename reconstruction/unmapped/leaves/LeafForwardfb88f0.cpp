// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb88f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb88f0 LeafForwardfb88f0::Forward
#include "LeafForwardfb88f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb88f0::Forward() { return leaf_target(this); }
