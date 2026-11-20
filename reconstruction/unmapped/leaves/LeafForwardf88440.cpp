// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88440, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88440 LeafForwardf88440::Forward
#include "LeafForwardf88440.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88440::Forward() { return leaf_target(this); }
