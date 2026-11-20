// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarde96860, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xe96860 LeafForwarde96860::Forward
#include "LeafForwarde96860.h"
extern "C" void* leaf_target(void*);
void* LeafForwarde96860::Forward() { return leaf_target(this); }
