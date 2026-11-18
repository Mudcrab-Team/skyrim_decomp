// Source exposure: binary-analysis; no external implementation reused.
// LeafForward840320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x840320 LeafForward840320::Forward
#include "LeafForward840320.h"
extern "C" void* leaf_target(void*);
void* LeafForward840320::Forward() { return leaf_target(this); }
