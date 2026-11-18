// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfba310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfba310 LeafForwardfba310::Forward
#include "LeafForwardfba310.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfba310::Forward() { return leaf_target(this); }
