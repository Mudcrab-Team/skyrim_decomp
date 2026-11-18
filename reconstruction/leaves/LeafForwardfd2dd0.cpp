// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd2dd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd2dd0 LeafForwardfd2dd0::Forward
#include "LeafForwardfd2dd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd2dd0::Forward() { return leaf_target(this); }
