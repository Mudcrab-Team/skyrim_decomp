// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaf4d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaf4d0 LeafForwardfaf4d0::Forward
#include "LeafForwardfaf4d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaf4d0::Forward() { return leaf_target(this); }
