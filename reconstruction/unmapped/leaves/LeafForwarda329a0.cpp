// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda329a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa329a0 LeafForwarda329a0::Forward
#include "LeafForwarda329a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda329a0::Forward() { return leaf_target(this); }
