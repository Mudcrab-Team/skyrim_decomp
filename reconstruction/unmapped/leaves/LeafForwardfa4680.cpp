// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4680, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4680 LeafForwardfa4680::Forward
#include "LeafForwardfa4680.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4680::Forward() { return leaf_target(this); }
