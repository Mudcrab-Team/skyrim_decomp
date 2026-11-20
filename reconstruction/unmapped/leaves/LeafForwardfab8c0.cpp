// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfab8c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfab8c0 LeafForwardfab8c0::Forward
#include "LeafForwardfab8c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfab8c0::Forward() { return leaf_target(this); }
