// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8a230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8a230 LeafForwardf8a230::Forward
#include "LeafForwardf8a230.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8a230::Forward() { return leaf_target(this); }
