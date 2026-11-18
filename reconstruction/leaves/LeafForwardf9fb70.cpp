// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9fb70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9fb70 LeafForwardf9fb70::Forward
#include "LeafForwardf9fb70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9fb70::Forward() { return leaf_target(this); }
