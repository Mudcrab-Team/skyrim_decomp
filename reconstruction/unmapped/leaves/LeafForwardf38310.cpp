// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf38310, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf38310 LeafForwardf38310::Forward
#include "LeafForwardf38310.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf38310::Forward() { return leaf_target(this); }
