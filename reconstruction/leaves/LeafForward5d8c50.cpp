// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5d8c50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5d8c50 LeafForward5d8c50::Forward
#include "LeafForward5d8c50.h"
extern "C" void* leaf_target(void*);
void* LeafForward5d8c50::Forward() { return leaf_target(this); }
