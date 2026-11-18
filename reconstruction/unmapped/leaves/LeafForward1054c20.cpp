// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1054c20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1054c20 LeafForward1054c20::Forward
#include "LeafForward1054c20.h"
extern "C" void* leaf_target(void*);
void* LeafForward1054c20::Forward() { return leaf_target(this); }
