// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc03c50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc03c50 LeafForwardc03c50::Forward
#include "LeafForwardc03c50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc03c50::Forward() { return leaf_target(this); }
