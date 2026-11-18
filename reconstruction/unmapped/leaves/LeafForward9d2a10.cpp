// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9d2a10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9d2a10 LeafForward9d2a10::Forward
#include "LeafForward9d2a10.h"
extern "C" void* leaf_target(void*);
void* LeafForward9d2a10::Forward() { return leaf_target(this); }
