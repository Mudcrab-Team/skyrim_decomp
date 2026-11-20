// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4c50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4c50 LeafForwardfa4c50::Forward
#include "LeafForwardfa4c50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4c50::Forward() { return leaf_target(this); }
