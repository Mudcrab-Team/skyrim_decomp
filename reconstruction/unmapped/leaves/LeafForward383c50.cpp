// Source exposure: binary-analysis; no external implementation reused.
// LeafForward383c50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x383c50 LeafForward383c50::Forward
#include "LeafForward383c50.h"
extern "C" void* leaf_target(void*);
void* LeafForward383c50::Forward() { return leaf_target(this); }
