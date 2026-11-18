// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcd6840, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcd6840 LeafForwardcd6840::Forward
#include "LeafForwardcd6840.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcd6840::Forward() { return leaf_target(this); }
