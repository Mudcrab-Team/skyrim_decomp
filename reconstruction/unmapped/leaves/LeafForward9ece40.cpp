// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ece40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ece40 LeafForward9ece40::Forward
#include "LeafForward9ece40.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ece40::Forward() { return leaf_target(this); }
