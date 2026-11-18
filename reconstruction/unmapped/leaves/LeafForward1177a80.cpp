// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1177a80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1177a80 LeafForward1177a80::Forward
#include "LeafForward1177a80.h"
extern "C" void* leaf_target(void*);
void* LeafForward1177a80::Forward() { return leaf_target(this); }
