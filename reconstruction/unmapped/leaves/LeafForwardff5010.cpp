// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff5010, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff5010 LeafForwardff5010::Forward
#include "LeafForwardff5010.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff5010::Forward() { return leaf_target(this); }
