// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeffce0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeffce0 LeafForwardeffce0::Forward
#include "LeafForwardeffce0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeffce0::Forward() { return leaf_target(this); }
