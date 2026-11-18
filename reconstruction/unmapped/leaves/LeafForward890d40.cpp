// Source exposure: binary-analysis; no external implementation reused.
// LeafForward890d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x890d40 LeafForward890d40::Forward
#include "LeafForward890d40.h"
extern "C" void* leaf_target(void*);
void* LeafForward890d40::Forward() { return leaf_target(this); }
