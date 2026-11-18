// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfd50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfd50 LeafForwardfdfd50::Forward
#include "LeafForwardfdfd50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfd50::Forward() { return leaf_target(this); }
