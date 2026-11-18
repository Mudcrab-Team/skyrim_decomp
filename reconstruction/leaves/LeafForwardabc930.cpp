// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardabc930, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xabc930 LeafForwardabc930::Forward
#include "LeafForwardabc930.h"
extern "C" void* leaf_target(void*);
void* LeafForwardabc930::Forward() { return leaf_target(this); }
