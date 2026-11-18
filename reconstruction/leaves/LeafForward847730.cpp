// Source exposure: binary-analysis; no external implementation reused.
// LeafForward847730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x847730 LeafForward847730::Forward
#include "LeafForward847730.h"
extern "C" void* leaf_target(void*);
void* LeafForward847730::Forward() { return leaf_target(this); }
