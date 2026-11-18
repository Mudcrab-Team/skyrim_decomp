// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85f50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85f50 LeafForwardf85f50::Forward
#include "LeafForwardf85f50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85f50::Forward() { return leaf_target(this); }
