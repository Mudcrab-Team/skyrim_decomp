// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd9240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd9240 LeafForwardbd9240::Forward
#include "LeafForwardbd9240.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd9240::Forward() { return leaf_target(this); }
