// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4e3380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4e3380 LeafForward4e3380::Forward
#include "LeafForward4e3380.h"
extern "C" void* leaf_target(void*);
void* LeafForward4e3380::Forward() { return leaf_target(this); }
