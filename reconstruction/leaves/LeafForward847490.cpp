// Source exposure: binary-analysis; no external implementation reused.
// LeafForward847490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x847490 LeafForward847490::Forward
#include "LeafForward847490.h"
extern "C" void* leaf_target(void*);
void* LeafForward847490::Forward() { return leaf_target(this); }
