// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb8300, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb8300 LeafForwardfb8300::Forward
#include "LeafForwardfb8300.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb8300::Forward() { return leaf_target(this); }
