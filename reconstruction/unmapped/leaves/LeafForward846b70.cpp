// Source exposure: binary-analysis; no external implementation reused.
// LeafForward846b70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x846b70 LeafForward846b70::Forward
#include "LeafForward846b70.h"
extern "C" void* leaf_target(void*);
void* LeafForward846b70::Forward() { return leaf_target(this); }
