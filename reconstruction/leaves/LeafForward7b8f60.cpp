// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7b8f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7b8f60 LeafForward7b8f60::Forward
#include "LeafForward7b8f60.h"
extern "C" void* leaf_target(void*);
void* LeafForward7b8f60::Forward() { return leaf_target(this); }
