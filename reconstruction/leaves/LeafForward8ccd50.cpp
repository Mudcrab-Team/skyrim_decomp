// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ccd50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ccd50 LeafForward8ccd50::Forward
#include "LeafForward8ccd50.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ccd50::Forward() { return leaf_target(this); }
