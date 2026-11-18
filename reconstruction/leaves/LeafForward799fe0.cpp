// Source exposure: binary-analysis; no external implementation reused.
// LeafForward799fe0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x799fe0 LeafForward799fe0::Forward
#include "LeafForward799fe0.h"
extern "C" void* leaf_target(void*);
void* LeafForward799fe0::Forward() { return leaf_target(this); }
