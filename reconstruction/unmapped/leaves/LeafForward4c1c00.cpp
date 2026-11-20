// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4c1c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4c1c00 LeafForward4c1c00::Forward
#include "LeafForward4c1c00.h"
extern "C" void* leaf_target(void*);
void* LeafForward4c1c00::Forward() { return leaf_target(this); }
