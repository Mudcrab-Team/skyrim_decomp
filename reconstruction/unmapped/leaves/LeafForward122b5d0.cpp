// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122b5d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122b5d0 LeafForward122b5d0::Forward
#include "LeafForward122b5d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward122b5d0::Forward() { return leaf_target(this); }
