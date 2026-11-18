// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4ee740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4ee740 LeafForward4ee740::Forward
#include "LeafForward4ee740.h"
extern "C" void* leaf_target(void*);
void* LeafForward4ee740::Forward() { return leaf_target(this); }
