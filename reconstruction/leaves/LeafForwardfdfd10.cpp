// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfd10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfd10 LeafForwardfdfd10::Forward
#include "LeafForwardfdfd10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfd10::Forward() { return leaf_target(this); }
