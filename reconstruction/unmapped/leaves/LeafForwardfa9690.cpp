// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa9690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa9690 LeafForwardfa9690::Forward
#include "LeafForwardfa9690.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa9690::Forward() { return leaf_target(this); }
