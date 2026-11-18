// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa0060, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa0060 LeafForwardfa0060::Forward
#include "LeafForwardfa0060.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa0060::Forward() { return leaf_target(this); }
