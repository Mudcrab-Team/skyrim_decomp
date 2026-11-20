// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88190 LeafForwardf88190::Forward
#include "LeafForwardf88190.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88190::Forward() { return leaf_target(this); }
