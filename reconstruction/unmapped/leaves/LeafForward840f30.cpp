// Source exposure: binary-analysis; no external implementation reused.
// LeafForward840f30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x840f30 LeafForward840f30::Forward
#include "LeafForward840f30.h"
extern "C" void* leaf_target(void*);
void* LeafForward840f30::Forward() { return leaf_target(this); }
