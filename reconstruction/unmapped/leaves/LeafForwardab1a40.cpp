// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardab1a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xab1a40 LeafForwardab1a40::Forward
#include "LeafForwardab1a40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardab1a40::Forward() { return leaf_target(this); }
