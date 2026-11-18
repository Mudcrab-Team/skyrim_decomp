// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6a4e20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6a4e20 LeafForward6a4e20::Forward
#include "LeafForward6a4e20.h"
extern "C" void* leaf_target(void*);
void* LeafForward6a4e20::Forward() { return leaf_target(this); }
