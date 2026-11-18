// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfeb0c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfeb0c0 LeafForwardfeb0c0::Forward
#include "LeafForwardfeb0c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfeb0c0::Forward() { return leaf_target(this); }
