// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10a7200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10a7200 LeafForward10a7200::Forward
#include "LeafForward10a7200.h"
extern "C" void* leaf_target(void*);
void* LeafForward10a7200::Forward() { return leaf_target(this); }
