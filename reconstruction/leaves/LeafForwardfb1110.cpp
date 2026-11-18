// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1110, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1110 LeafForwardfb1110::Forward
#include "LeafForwardfb1110.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1110::Forward() { return leaf_target(this); }
