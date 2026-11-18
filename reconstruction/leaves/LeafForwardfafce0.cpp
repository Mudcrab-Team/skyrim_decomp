// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfafce0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfafce0 LeafForwardfafce0::Forward
#include "LeafForwardfafce0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfafce0::Forward() { return leaf_target(this); }
