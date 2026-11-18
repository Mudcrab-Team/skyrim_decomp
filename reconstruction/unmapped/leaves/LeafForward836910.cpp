// Source exposure: binary-analysis; no external implementation reused.
// LeafForward836910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x836910 LeafForward836910::Forward
#include "LeafForward836910.h"
extern "C" void* leaf_target(void*);
void* LeafForward836910::Forward() { return leaf_target(this); }
