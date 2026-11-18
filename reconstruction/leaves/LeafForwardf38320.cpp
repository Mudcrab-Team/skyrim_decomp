// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf38320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf38320 LeafForwardf38320::Forward
#include "LeafForwardf38320.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf38320::Forward() { return leaf_target(this); }
