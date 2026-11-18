// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6d760, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6d760 LeafForwardf6d760::Forward
#include "LeafForwardf6d760.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6d760::Forward() { return leaf_target(this); }
