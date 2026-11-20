// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdff60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdff60 LeafForwardfdff60::Forward
#include "LeafForwardfdff60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdff60::Forward() { return leaf_target(this); }
