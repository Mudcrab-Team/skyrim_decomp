// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfafcf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfafcf0 LeafForwardfafcf0::Forward
#include "LeafForwardfafcf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfafcf0::Forward() { return leaf_target(this); }
