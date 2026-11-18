// Source exposure: binary-analysis; no external implementation reused.
// LeafForward799ff0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x799ff0 LeafForward799ff0::Forward
#include "LeafForward799ff0.h"
extern "C" void* leaf_target(void*);
void* LeafForward799ff0::Forward() { return leaf_target(this); }
