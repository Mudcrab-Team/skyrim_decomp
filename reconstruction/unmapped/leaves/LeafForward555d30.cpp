// Source exposure: binary-analysis; no external implementation reused.
// LeafForward555d30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x555d30 LeafForward555d30::Forward
#include "LeafForward555d30.h"
extern "C" void* leaf_target(void*);
void* LeafForward555d30::Forward() { return leaf_target(this); }
