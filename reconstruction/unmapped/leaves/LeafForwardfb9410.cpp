// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb9410, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb9410 LeafForwardfb9410::Forward
#include "LeafForwardfb9410.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb9410::Forward() { return leaf_target(this); }
