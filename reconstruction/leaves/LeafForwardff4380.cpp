// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff4380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff4380 LeafForwardff4380::Forward
#include "LeafForwardff4380.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff4380::Forward() { return leaf_target(this); }
