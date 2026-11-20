// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9fc70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9fc70 LeafForwardf9fc70::Forward
#include "LeafForwardf9fc70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9fc70::Forward() { return leaf_target(this); }
