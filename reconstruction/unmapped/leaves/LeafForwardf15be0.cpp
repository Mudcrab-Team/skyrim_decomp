// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf15be0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf15be0 LeafForwardf15be0::Forward
#include "LeafForwardf15be0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf15be0::Forward() { return leaf_target(this); }
