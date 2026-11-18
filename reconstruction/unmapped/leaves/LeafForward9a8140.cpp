// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9a8140, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9a8140 LeafForward9a8140::Forward
#include "LeafForward9a8140.h"
extern "C" void* leaf_target(void*);
void* LeafForward9a8140::Forward() { return leaf_target(this); }
