// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0fa80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0fa80 LeafForwardf0fa80::Forward
#include "LeafForwardf0fa80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0fa80::Forward() { return leaf_target(this); }
