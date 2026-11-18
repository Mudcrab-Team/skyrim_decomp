// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2dc490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2dc490 LeafForward2dc490::Forward
#include "LeafForward2dc490.h"
extern "C" void* leaf_target(void*);
void* LeafForward2dc490::Forward() { return leaf_target(this); }
