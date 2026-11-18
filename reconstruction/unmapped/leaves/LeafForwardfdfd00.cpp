// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfd00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfd00 LeafForwardfdfd00::Forward
#include "LeafForwardfdfd00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfd00::Forward() { return leaf_target(this); }
