// Source exposure: binary-analysis; no external implementation reused.
// LeafForward18c310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x18c310 LeafForward18c310::Forward
#include "LeafForward18c310.h"
extern "C" void* leaf_target(void*);
void* LeafForward18c310::Forward() { return leaf_target(this); }
