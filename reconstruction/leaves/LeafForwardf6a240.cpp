// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6a240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6a240 LeafForwardf6a240::Forward
#include "LeafForwardf6a240.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6a240::Forward() { return leaf_target(this); }
