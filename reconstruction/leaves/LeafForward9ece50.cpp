// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ece50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ece50 LeafForward9ece50::Forward
#include "LeafForward9ece50.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ece50::Forward() { return leaf_target(this); }
