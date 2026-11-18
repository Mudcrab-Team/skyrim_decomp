// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9fb80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9fb80 LeafForwardf9fb80::Forward
#include "LeafForwardf9fb80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9fb80::Forward() { return leaf_target(this); }
