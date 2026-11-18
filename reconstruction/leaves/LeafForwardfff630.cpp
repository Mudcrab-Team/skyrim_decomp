// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfff630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfff630 LeafForwardfff630::Forward
#include "LeafForwardfff630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfff630::Forward() { return leaf_target(this); }
