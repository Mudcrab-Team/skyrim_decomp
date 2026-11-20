// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11f00b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11f00b0 LeafForward11f00b0::Forward
#include "LeafForward11f00b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward11f00b0::Forward() { return leaf_target(this); }
