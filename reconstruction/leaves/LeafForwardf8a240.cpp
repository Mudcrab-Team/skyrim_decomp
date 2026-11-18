// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8a240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8a240 LeafForwardf8a240::Forward
#include "LeafForwardf8a240.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8a240::Forward() { return leaf_target(this); }
