// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6b5150, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6b5150 LeafForward6b5150::Forward
#include "LeafForward6b5150.h"
extern "C" void* leaf_target(void*);
void* LeafForward6b5150::Forward() { return leaf_target(this); }
