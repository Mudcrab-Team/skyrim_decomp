// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11d36b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11d36b0 LeafForward11d36b0::Forward
#include "LeafForward11d36b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward11d36b0::Forward() { return leaf_target(this); }
