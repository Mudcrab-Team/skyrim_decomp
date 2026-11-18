// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157b730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157b730 LeafForward157b730::Forward
#include "LeafForward157b730.h"
extern "C" void* leaf_target(void*);
void* LeafForward157b730::Forward() { return leaf_target(this); }
