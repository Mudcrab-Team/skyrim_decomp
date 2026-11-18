// Source exposure: binary-analysis; no external implementation reused.
// LeafForward995a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x995a40 LeafForward995a40::Forward
#include "LeafForward995a40.h"
extern "C" void* leaf_target(void*);
void* LeafForward995a40::Forward() { return leaf_target(this); }
