// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd9250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd9250 LeafForwardbd9250::Forward
#include "LeafForwardbd9250.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd9250::Forward() { return leaf_target(this); }
