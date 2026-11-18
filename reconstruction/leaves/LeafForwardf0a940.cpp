// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0a940, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0a940 LeafForwardf0a940::Forward
#include "LeafForwardf0a940.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0a940::Forward() { return leaf_target(this); }
