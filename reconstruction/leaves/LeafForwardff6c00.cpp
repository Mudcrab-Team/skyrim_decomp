// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6c00 LeafForwardff6c00::Forward
#include "LeafForwardff6c00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6c00::Forward() { return leaf_target(this); }
