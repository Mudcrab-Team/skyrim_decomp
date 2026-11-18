// Source exposure: binary-analysis; no external implementation reused.
// LeafForward80ab80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x80ab80 LeafForward80ab80::Forward
#include "LeafForward80ab80.h"
extern "C" void* leaf_target(void*);
void* LeafForward80ab80::Forward() { return leaf_target(this); }
