// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda6d480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa6d480 LeafForwarda6d480::Forward
#include "LeafForwarda6d480.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda6d480::Forward() { return leaf_target(this); }
