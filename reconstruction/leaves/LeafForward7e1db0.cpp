// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7e1db0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7e1db0 LeafForward7e1db0::Forward
#include "LeafForward7e1db0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7e1db0::Forward() { return leaf_target(this); }
