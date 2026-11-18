// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd8c30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd8c30 LeafForwardfd8c30::Forward
#include "LeafForwardfd8c30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd8c30::Forward() { return leaf_target(this); }
