// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc0300, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc0300 LeafForwardfc0300::Forward
#include "LeafForwardfc0300.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc0300::Forward() { return leaf_target(this); }
