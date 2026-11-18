// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa7e50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa7e50 LeafForwardfa7e50::Forward
#include "LeafForwardfa7e50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa7e50::Forward() { return leaf_target(this); }
