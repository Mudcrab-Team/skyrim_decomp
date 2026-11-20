// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeed470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeed470 LeafForwardeed470::Forward
#include "LeafForwardeed470.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeed470::Forward() { return leaf_target(this); }
