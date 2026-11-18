// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda329b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa329b0 LeafForwarda329b0::Forward
#include "LeafForwarda329b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda329b0::Forward() { return leaf_target(this); }
