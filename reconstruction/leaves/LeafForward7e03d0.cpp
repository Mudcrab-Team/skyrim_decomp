// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7e03d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7e03d0 LeafForward7e03d0::Forward
#include "LeafForward7e03d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7e03d0::Forward() { return leaf_target(this); }
