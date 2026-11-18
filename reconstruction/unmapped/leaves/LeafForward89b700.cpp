// Source exposure: binary-analysis; no external implementation reused.
// LeafForward89b700, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x89b700 LeafForward89b700::Forward
#include "LeafForward89b700.h"
extern "C" void* leaf_target(void*);
void* LeafForward89b700::Forward() { return leaf_target(this); }
