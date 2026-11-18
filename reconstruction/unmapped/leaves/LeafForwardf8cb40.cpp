// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8cb40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8cb40 LeafForwardf8cb40::Forward
#include "LeafForwardf8cb40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8cb40::Forward() { return leaf_target(this); }
