// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1227640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1227640 LeafForward1227640::Forward
#include "LeafForward1227640.h"
extern "C" void* leaf_target(void*);
void* LeafForward1227640::Forward() { return leaf_target(this); }
