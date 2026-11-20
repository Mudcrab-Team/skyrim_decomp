// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4260 LeafForwardfa4260::Forward
#include "LeafForwardfa4260.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4260::Forward() { return leaf_target(this); }
