// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f250 LeafForwardf0f250::Forward
#include "LeafForwardf0f250.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f250::Forward() { return leaf_target(this); }
