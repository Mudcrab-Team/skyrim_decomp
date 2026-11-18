// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda9bf90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa9bf90 LeafForwarda9bf90::Forward
#include "LeafForwarda9bf90.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda9bf90::Forward() { return leaf_target(this); }
