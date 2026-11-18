// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc03c60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc03c60 LeafForwardc03c60::Forward
#include "LeafForwardc03c60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc03c60::Forward() { return leaf_target(this); }
