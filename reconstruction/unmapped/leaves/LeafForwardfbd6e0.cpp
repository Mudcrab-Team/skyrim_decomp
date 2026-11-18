// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbd6e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbd6e0 LeafForwardfbd6e0::Forward
#include "LeafForwardfbd6e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbd6e0::Forward() { return leaf_target(this); }
