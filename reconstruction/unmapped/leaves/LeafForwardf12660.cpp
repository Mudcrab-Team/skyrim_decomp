// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf12660, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf12660 LeafForwardf12660::Forward
#include "LeafForwardf12660.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf12660::Forward() { return leaf_target(this); }
