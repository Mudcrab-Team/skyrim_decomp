// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf15c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf15c10 LeafForwardf15c10::Forward
#include "LeafForwardf15c10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf15c10::Forward() { return leaf_target(this); }
