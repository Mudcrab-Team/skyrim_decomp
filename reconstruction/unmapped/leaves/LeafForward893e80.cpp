// Source exposure: binary-analysis; no external implementation reused.
// LeafForward893e80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x893e80 LeafForward893e80::Forward
#include "LeafForward893e80.h"
extern "C" void* leaf_target(void*);
void* LeafForward893e80::Forward() { return leaf_target(this); }
