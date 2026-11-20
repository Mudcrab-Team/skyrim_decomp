// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9fb60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9fb60 LeafForwardf9fb60::Forward
#include "LeafForwardf9fb60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9fb60::Forward() { return leaf_target(this); }
