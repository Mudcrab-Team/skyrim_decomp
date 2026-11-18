// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb3090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb3090 LeafForwardfb3090::Forward
#include "LeafForwardfb3090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb3090::Forward() { return leaf_target(this); }
