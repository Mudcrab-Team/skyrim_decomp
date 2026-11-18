// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4c60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4c60 LeafForwardfa4c60::Forward
#include "LeafForwardfa4c60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4c60::Forward() { return leaf_target(this); }
