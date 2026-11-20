// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6ba100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6ba100 LeafForward6ba100::Forward
#include "LeafForward6ba100.h"
extern "C" void* leaf_target(void*);
void* LeafForward6ba100::Forward() { return leaf_target(this); }
