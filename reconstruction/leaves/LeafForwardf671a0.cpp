// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf671a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf671a0 LeafForwardf671a0::Forward
#include "LeafForwardf671a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf671a0::Forward() { return leaf_target(this); }
