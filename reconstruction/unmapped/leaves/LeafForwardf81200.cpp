// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf81200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf81200 LeafForwardf81200::Forward
#include "LeafForwardf81200.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf81200::Forward() { return leaf_target(this); }
