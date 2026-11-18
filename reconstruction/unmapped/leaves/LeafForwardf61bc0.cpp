// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf61bc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf61bc0 LeafForwardf61bc0::Forward
#include "LeafForwardf61bc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf61bc0::Forward() { return leaf_target(this); }
