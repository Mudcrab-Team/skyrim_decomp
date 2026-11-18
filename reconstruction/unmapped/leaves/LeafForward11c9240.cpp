// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11c9240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11c9240 LeafForward11c9240::Forward
#include "LeafForward11c9240.h"
extern "C" void* leaf_target(void*);
void* LeafForward11c9240::Forward() { return leaf_target(this); }
