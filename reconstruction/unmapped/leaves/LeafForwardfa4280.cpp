// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4280, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4280 LeafForwardfa4280::Forward
#include "LeafForwardfa4280.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4280::Forward() { return leaf_target(this); }
