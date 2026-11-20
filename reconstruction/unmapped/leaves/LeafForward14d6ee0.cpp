// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14d6ee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14d6ee0 LeafForward14d6ee0::Forward
#include "LeafForward14d6ee0.h"
extern "C" void* leaf_target(void*);
void* LeafForward14d6ee0::Forward() { return leaf_target(this); }
