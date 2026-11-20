// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121b950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121b950 LeafForward121b950::Forward
#include "LeafForward121b950.h"
extern "C" void* leaf_target(void*);
void* LeafForward121b950::Forward() { return leaf_target(this); }
