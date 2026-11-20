// Source exposure: binary-analysis; no external implementation reused.
// LeafForward865220, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x865220 LeafForward865220::Forward
#include "LeafForward865220.h"
extern "C" void* leaf_target(void*);
void* LeafForward865220::Forward() { return leaf_target(this); }
