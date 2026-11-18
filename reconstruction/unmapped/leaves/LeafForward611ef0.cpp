// Source exposure: binary-analysis; no external implementation reused.
// LeafForward611ef0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x611ef0 LeafForward611ef0::Forward
#include "LeafForward611ef0.h"
extern "C" void* leaf_target(void*);
void* LeafForward611ef0::Forward() { return leaf_target(this); }
