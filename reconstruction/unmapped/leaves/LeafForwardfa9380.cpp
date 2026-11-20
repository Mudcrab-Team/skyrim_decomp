// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa9380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa9380 LeafForwardfa9380::Forward
#include "LeafForwardfa9380.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa9380::Forward() { return leaf_target(this); }
