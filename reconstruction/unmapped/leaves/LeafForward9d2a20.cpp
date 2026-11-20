// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9d2a20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9d2a20 LeafForward9d2a20::Forward
#include "LeafForward9d2a20.h"
extern "C" void* leaf_target(void*);
void* LeafForward9d2a20::Forward() { return leaf_target(this); }
