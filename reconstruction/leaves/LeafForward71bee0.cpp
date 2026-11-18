// Source exposure: binary-analysis; no external implementation reused.
// LeafForward71bee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x71bee0 LeafForward71bee0::Forward
#include "LeafForward71bee0.h"
extern "C" void* leaf_target(void*);
void* LeafForward71bee0::Forward() { return leaf_target(this); }
