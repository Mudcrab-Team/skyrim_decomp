// Source exposure: binary-analysis; no external implementation reused.
// LeafForward549ec0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x549ec0 LeafForward549ec0::Forward
#include "LeafForward549ec0.h"
extern "C" void* leaf_target(void*);
void* LeafForward549ec0::Forward() { return leaf_target(this); }
