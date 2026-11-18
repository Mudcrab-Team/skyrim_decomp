// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15a7f50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15a7f50 LeafForward15a7f50::Forward
#include "LeafForward15a7f50.h"
extern "C" void* leaf_target(void*);
void* LeafForward15a7f50::Forward() { return leaf_target(this); }
