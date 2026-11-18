// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc1770, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc1770 LeafForwardfc1770::Forward
#include "LeafForwardfc1770.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc1770::Forward() { return leaf_target(this); }
