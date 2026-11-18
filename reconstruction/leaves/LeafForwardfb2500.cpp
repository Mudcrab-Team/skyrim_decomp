// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb2500, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb2500 LeafForwardfb2500::Forward
#include "LeafForwardfb2500.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb2500::Forward() { return leaf_target(this); }
