// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10ca40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10ca40 LeafForward10ca40::Forward
#include "LeafForward10ca40.h"
extern "C" void* leaf_target(void*);
void* LeafForward10ca40::Forward() { return leaf_target(this); }
