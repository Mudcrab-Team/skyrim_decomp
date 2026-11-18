// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf4f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf4f0 LeafForwardfaf4f0::Forward
#include "LeafForwardfaf4f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf4f0::Forward() { return leaf_target(this); }
