// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ec270, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ec270 LeafForward8ec270::Forward
#include "LeafForward8ec270.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ec270::Forward() { return leaf_target(this); }
