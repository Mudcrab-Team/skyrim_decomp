// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa7e60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa7e60 LeafForwardfa7e60::Forward
#include "LeafForwardfa7e60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa7e60::Forward() { return leaf_target(this); }
