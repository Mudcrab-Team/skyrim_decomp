// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb7080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb7080 LeafForwardbb7080::Forward
#include "LeafForwardbb7080.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb7080::Forward() { return leaf_target(this); }
