// Source exposure: binary-analysis; no external implementation reused.
// LeafForward85ee40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x85ee40 LeafForward85ee40::Forward
#include "LeafForward85ee40.h"
extern "C" void* leaf_target(void*);
void* LeafForward85ee40::Forward() { return leaf_target(this); }
