// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd7820, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd7820 LeafForwardbd7820::Forward
#include "LeafForwardbd7820.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd7820::Forward() { return leaf_target(this); }
