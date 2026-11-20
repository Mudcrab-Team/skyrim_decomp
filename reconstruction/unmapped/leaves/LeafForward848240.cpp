// Source exposure: binary-analysis; no external implementation reused.
// LeafForward848240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x848240 LeafForward848240::Forward
#include "LeafForward848240.h"
extern "C" void* leaf_target(void*);
void* LeafForward848240::Forward() { return leaf_target(this); }
