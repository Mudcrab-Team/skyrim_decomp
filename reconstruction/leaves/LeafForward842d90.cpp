// Source exposure: binary-analysis; no external implementation reused.
// LeafForward842d90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x842d90 LeafForward842d90::Forward
#include "LeafForward842d90.h"
extern "C" void* leaf_target(void*);
void* LeafForward842d90::Forward() { return leaf_target(this); }
