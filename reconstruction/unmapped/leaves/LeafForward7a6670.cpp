// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a6670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a6670 LeafForward7a6670::Forward
#include "LeafForward7a6670.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a6670::Forward() { return leaf_target(this); }
