// Source exposure: binary-analysis; no external implementation reused.
// LeafForward844e30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x844e30 LeafForward844e30::Forward
#include "LeafForward844e30.h"
extern "C" void* leaf_target(void*);
void* LeafForward844e30::Forward() { return leaf_target(this); }
