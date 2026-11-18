// Source exposure: binary-analysis; no external implementation reused.
// LeafForward612e60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x612e60 LeafForward612e60::Forward
#include "LeafForward612e60.h"
extern "C" void* leaf_target(void*);
void* LeafForward612e60::Forward() { return leaf_target(this); }
