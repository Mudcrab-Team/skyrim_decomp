// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73bc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73bc0 LeafForwardf73bc0::Forward
#include "LeafForwardf73bc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73bc0::Forward() { return leaf_target(this); }
