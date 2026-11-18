// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10dde70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10dde70 LeafForward10dde70::Forward
#include "LeafForward10dde70.h"
extern "C" void* leaf_target(void*);
void* LeafForward10dde70::Forward() { return leaf_target(this); }
