// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6310 LeafForwardff6310::Forward
#include "LeafForwardff6310.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6310::Forward() { return leaf_target(this); }
