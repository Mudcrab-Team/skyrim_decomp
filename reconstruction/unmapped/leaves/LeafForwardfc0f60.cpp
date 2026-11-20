// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc0f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc0f60 LeafForwardfc0f60::Forward
#include "LeafForwardfc0f60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc0f60::Forward() { return leaf_target(this); }
