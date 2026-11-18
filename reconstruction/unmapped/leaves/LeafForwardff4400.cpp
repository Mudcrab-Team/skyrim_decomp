// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff4400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff4400 LeafForwardff4400::Forward
#include "LeafForwardff4400.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff4400::Forward() { return leaf_target(this); }
