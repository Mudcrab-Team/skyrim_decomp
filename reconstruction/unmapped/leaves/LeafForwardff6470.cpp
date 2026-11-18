// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6470 LeafForwardff6470::Forward
#include "LeafForwardff6470.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6470::Forward() { return leaf_target(this); }
