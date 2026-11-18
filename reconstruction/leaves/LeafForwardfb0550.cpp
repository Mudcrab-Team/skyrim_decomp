// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb0550, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb0550 LeafForwardfb0550::Forward
#include "LeafForwardfb0550.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb0550::Forward() { return leaf_target(this); }
