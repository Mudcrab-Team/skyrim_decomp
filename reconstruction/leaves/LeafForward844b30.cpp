// Source exposure: binary-analysis; no external implementation reused.
// LeafForward844b30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x844b30 LeafForward844b30::Forward
#include "LeafForward844b30.h"
extern "C" void* leaf_target(void*);
void* LeafForward844b30::Forward() { return leaf_target(this); }
