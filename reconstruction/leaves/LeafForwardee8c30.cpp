// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardee8c30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xee8c30 LeafForwardee8c30::Forward
#include "LeafForwardee8c30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardee8c30::Forward() { return leaf_target(this); }
