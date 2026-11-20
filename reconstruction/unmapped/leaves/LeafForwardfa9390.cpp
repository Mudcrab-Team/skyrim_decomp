// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa9390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa9390 LeafForwardfa9390::Forward
#include "LeafForwardfa9390.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa9390::Forward() { return leaf_target(this); }
