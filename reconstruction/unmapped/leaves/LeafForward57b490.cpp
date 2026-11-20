// Source exposure: binary-analysis; no external implementation reused.
// LeafForward57b490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x57b490 LeafForward57b490::Forward
#include "LeafForward57b490.h"
extern "C" void* leaf_target(void*);
void* LeafForward57b490::Forward() { return leaf_target(this); }
