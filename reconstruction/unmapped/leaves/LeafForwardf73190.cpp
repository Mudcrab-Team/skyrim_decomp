// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73190 LeafForwardf73190::Forward
#include "LeafForwardf73190.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73190::Forward() { return leaf_target(this); }
