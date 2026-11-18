// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4d2a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4d2a40 LeafForward4d2a40::Forward
#include "LeafForward4d2a40.h"
extern "C" void* leaf_target(void*);
void* LeafForward4d2a40::Forward() { return leaf_target(this); }
