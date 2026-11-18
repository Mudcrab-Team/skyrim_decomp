// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11dd370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11dd370 LeafForward11dd370::Forward
#include "LeafForward11dd370.h"
extern "C" void* leaf_target(void*);
void* LeafForward11dd370::Forward() { return leaf_target(this); }
