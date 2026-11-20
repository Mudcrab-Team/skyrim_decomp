// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6c10 LeafForwardff6c10::Forward
#include "LeafForwardff6c10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6c10::Forward() { return leaf_target(this); }
