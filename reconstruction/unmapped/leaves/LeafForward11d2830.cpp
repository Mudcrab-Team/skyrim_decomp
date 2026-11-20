// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11d2830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11d2830 LeafForward11d2830::Forward
#include "LeafForward11d2830.h"
extern "C" void* leaf_target(void*);
void* LeafForward11d2830::Forward() { return leaf_target(this); }
