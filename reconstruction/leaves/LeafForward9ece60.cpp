// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ece60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ece60 LeafForward9ece60::Forward
#include "LeafForward9ece60.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ece60::Forward() { return leaf_target(this); }
