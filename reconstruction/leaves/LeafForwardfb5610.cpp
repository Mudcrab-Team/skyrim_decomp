// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb5610, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb5610 LeafForwardfb5610::Forward
#include "LeafForwardfb5610.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb5610::Forward() { return leaf_target(this); }
