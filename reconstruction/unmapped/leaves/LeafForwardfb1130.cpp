// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1130, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1130 LeafForwardfb1130::Forward
#include "LeafForwardfb1130.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1130::Forward() { return leaf_target(this); }
