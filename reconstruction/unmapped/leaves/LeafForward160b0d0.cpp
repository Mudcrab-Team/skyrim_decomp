// Source exposure: binary-analysis; no external implementation reused.
// LeafForward160b0d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x160b0d0 LeafForward160b0d0::Forward
#include "LeafForward160b0d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward160b0d0::Forward() { return leaf_target(this); }
