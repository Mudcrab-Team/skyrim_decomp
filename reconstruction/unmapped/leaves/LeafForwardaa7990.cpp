// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaa7990, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaa7990 LeafForwardaa7990::Forward
#include "LeafForwardaa7990.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaa7990::Forward() { return leaf_target(this); }
