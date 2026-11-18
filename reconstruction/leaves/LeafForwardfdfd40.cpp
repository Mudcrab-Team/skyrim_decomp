// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfd40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfd40 LeafForwardfdfd40::Forward
#include "LeafForwardfdfd40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfd40::Forward() { return leaf_target(this); }
