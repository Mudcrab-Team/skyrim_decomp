// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda68060, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa68060 LeafForwarda68060::Forward
#include "LeafForwarda68060.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda68060::Forward() { return leaf_target(this); }
