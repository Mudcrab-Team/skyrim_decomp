// Source exposure: binary-analysis; no external implementation reused.
// LeafForward38af50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x38af50 LeafForward38af50::Forward
#include "LeafForward38af50.h"
extern "C" void* leaf_target(void*);
void* LeafForward38af50::Forward() { return leaf_target(this); }
