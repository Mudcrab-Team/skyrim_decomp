// Source exposure: binary-analysis; no external implementation reused.
// LeafForward847f30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x847f30 LeafForward847f30::Forward
#include "LeafForward847f30.h"
extern "C" void* leaf_target(void*);
void* LeafForward847f30::Forward() { return leaf_target(this); }
