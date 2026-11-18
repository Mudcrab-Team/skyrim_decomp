// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5f3ce0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5f3ce0 LeafForward5f3ce0::Forward
#include "LeafForward5f3ce0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5f3ce0::Forward() { return leaf_target(this); }
