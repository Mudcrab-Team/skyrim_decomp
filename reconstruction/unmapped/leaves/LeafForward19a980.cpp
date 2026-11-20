// Source exposure: binary-analysis; no external implementation reused.
// LeafForward19a980, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x19a980 LeafForward19a980::Forward
#include "LeafForward19a980.h"
extern "C" void* leaf_target(void*);
void* LeafForward19a980::Forward() { return leaf_target(this); }
