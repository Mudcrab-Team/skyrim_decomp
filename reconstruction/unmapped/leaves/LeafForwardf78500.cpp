// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78500 LeafForwardf78500::Forward
#include "LeafForwardf78500.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78500::Forward() { return leaf_target(this); }
