// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf4c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf4c0 LeafForwardfaf4c0::Forward
#include "LeafForwardfaf4c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf4c0::Forward() { return leaf_target(this); }
