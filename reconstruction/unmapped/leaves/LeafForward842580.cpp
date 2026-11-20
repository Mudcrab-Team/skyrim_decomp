// Source exposure: binary-analysis; no external implementation reused.
// LeafForward842580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x842580 LeafForward842580::Forward
#include "LeafForward842580.h"
extern "C" void* leaf_target(void*);
void* LeafForward842580::Forward() { return leaf_target(this); }
