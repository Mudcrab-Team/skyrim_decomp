// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8a690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8a690 LeafForwardf8a690::Forward
#include "LeafForwardf8a690.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8a690::Forward() { return leaf_target(this); }
