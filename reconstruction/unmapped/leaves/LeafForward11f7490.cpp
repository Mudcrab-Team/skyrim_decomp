// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11f7490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11f7490 LeafForward11f7490::Forward
#include "LeafForward11f7490.h"
extern "C" void* leaf_target(void*);
void* LeafForward11f7490::Forward() { return leaf_target(this); }
