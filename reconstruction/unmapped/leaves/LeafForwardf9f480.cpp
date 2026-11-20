// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9f480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9f480 LeafForwardf9f480::Forward
#include "LeafForwardf9f480.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9f480::Forward() { return leaf_target(this); }
