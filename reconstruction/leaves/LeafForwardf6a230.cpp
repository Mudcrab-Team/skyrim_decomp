// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6a230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6a230 LeafForwardf6a230::Forward
#include "LeafForwardf6a230.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6a230::Forward() { return leaf_target(this); }
