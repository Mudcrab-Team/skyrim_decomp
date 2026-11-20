// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaabb80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaabb80 LeafForwardaabb80::Forward
#include "LeafForwardaabb80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaabb80::Forward() { return leaf_target(this); }
