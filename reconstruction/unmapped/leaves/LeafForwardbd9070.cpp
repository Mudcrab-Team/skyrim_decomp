// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd9070, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd9070 LeafForwardbd9070::Forward
#include "LeafForwardbd9070.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd9070::Forward() { return leaf_target(this); }
