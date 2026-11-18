// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff37d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff37d0 LeafForwardff37d0::Forward
#include "LeafForwardff37d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff37d0::Forward() { return leaf_target(this); }
