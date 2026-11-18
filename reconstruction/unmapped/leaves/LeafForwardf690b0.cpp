// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf690b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf690b0 LeafForwardf690b0::Forward
#include "LeafForwardf690b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf690b0::Forward() { return leaf_target(this); }
