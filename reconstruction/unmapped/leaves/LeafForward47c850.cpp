// Source exposure: binary-analysis; no external implementation reused.
// LeafForward47c850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x47c850 LeafForward47c850::Forward
#include "LeafForward47c850.h"
extern "C" void* leaf_target(void*);
void* LeafForward47c850::Forward() { return leaf_target(this); }
