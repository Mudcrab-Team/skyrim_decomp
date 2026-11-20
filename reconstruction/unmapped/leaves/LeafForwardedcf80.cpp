// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardedcf80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xedcf80 LeafForwardedcf80::Forward
#include "LeafForwardedcf80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardedcf80::Forward() { return leaf_target(this); }
