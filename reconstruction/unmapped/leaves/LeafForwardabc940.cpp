// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardabc940, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xabc940 LeafForwardabc940::Forward
#include "LeafForwardabc940.h"
extern "C" void* leaf_target(void*);
void* LeafForwardabc940::Forward() { return leaf_target(this); }
