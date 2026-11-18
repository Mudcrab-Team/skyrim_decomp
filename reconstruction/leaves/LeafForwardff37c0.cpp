// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff37c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff37c0 LeafForwardff37c0::Forward
#include "LeafForwardff37c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff37c0::Forward() { return leaf_target(this); }
