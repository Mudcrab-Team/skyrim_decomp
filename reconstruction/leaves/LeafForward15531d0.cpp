// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15531d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15531d0 LeafForward15531d0::Forward
#include "LeafForward15531d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward15531d0::Forward() { return leaf_target(this); }
