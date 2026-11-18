// Source exposure: binary-analysis; no external implementation reused.
// LeafForward80f580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x80f580 LeafForward80f580::Forward
#include "LeafForward80f580.h"
extern "C" void* leaf_target(void*);
void* LeafForward80f580::Forward() { return leaf_target(this); }
