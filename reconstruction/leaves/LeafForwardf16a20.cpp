// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf16a20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf16a20 LeafForwardf16a20::Forward
#include "LeafForwardf16a20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf16a20::Forward() { return leaf_target(this); }
