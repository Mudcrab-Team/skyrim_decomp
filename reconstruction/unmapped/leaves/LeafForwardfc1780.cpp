// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc1780, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc1780 LeafForwardfc1780::Forward
#include "LeafForwardfc1780.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc1780::Forward() { return leaf_target(this); }
