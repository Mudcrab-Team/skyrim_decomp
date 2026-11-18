// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbd6f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbd6f0 LeafForwardfbd6f0::Forward
#include "LeafForwardfbd6f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbd6f0::Forward() { return leaf_target(this); }
