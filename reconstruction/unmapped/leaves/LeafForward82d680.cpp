// Source exposure: binary-analysis; no external implementation reused.
// LeafForward82d680, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x82d680 LeafForward82d680::Forward
#include "LeafForward82d680.h"
extern "C" void* leaf_target(void*);
void* LeafForward82d680::Forward() { return leaf_target(this); }
