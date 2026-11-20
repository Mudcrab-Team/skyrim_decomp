// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12f4230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12f4230 LeafForward12f4230::Forward
#include "LeafForward12f4230.h"
extern "C" void* leaf_target(void*);
void* LeafForward12f4230::Forward() { return leaf_target(this); }
