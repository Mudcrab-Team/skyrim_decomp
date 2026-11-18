// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4197a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4197a0 LeafForward4197a0::Forward
#include "LeafForward4197a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward4197a0::Forward() { return leaf_target(this); }
