// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarde005e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xe005e0 LeafForwarde005e0::Forward
#include "LeafForwarde005e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarde005e0::Forward() { return leaf_target(this); }
