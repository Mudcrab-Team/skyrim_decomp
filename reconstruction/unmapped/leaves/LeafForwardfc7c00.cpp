// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc7c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc7c00 LeafForwardfc7c00::Forward
#include "LeafForwardfc7c00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc7c00::Forward() { return leaf_target(this); }
