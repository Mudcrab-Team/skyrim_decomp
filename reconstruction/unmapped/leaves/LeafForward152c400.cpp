// Source exposure: binary-analysis; no external implementation reused.
// LeafForward152c400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x152c400 LeafForward152c400::Forward
#include "LeafForward152c400.h"
extern "C" void* leaf_target(void*);
void* LeafForward152c400::Forward() { return leaf_target(this); }
