// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4f3650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4f3650 LeafForward4f3650::Forward
#include "LeafForward4f3650.h"
extern "C" void* leaf_target(void*);
void* LeafForward4f3650::Forward() { return leaf_target(this); }
