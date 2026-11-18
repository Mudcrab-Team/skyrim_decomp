// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf4e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf4e0 LeafForwardfaf4e0::Forward
#include "LeafForwardfaf4e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf4e0::Forward() { return leaf_target(this); }
