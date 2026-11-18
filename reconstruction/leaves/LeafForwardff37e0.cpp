// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff37e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff37e0 LeafForwardff37e0::Forward
#include "LeafForwardff37e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff37e0::Forward() { return leaf_target(this); }
