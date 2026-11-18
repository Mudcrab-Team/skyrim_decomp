// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14e9080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14e9080 LeafForward14e9080::Forward
#include "LeafForward14e9080.h"
extern "C" void* leaf_target(void*);
void* LeafForward14e9080::Forward() { return leaf_target(this); }
