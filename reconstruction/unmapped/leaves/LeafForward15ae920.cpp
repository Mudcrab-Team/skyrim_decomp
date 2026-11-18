// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15ae920, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15ae920 LeafForward15ae920::Forward
#include "LeafForward15ae920.h"
extern "C" void* leaf_target(void*);
void* LeafForward15ae920::Forward() { return leaf_target(this); }
