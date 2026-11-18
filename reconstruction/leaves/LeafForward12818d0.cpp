// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12818d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12818d0 LeafForward12818d0::Forward
#include "LeafForward12818d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward12818d0::Forward() { return leaf_target(this); }
