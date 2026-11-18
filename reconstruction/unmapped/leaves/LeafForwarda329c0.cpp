// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda329c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa329c0 LeafForwarda329c0::Forward
#include "LeafForwarda329c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda329c0::Forward() { return leaf_target(this); }
