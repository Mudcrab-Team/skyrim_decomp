// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12b4320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12b4320 LeafForward12b4320::Forward
#include "LeafForward12b4320.h"
extern "C" void* leaf_target(void*);
void* LeafForward12b4320::Forward() { return leaf_target(this); }
