// Source exposure: binary-analysis; no external implementation reused.
// LeafForward835a70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x835a70 LeafForward835a70::Forward
#include "LeafForward835a70.h"
extern "C" void* leaf_target(void*);
void* LeafForward835a70::Forward() { return leaf_target(this); }
