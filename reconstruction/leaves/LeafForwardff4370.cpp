// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff4370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff4370 LeafForwardff4370::Forward
#include "LeafForwardff4370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff4370::Forward() { return leaf_target(this); }
