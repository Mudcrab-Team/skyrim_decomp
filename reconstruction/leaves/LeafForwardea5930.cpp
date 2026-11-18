// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardea5930, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xea5930 LeafForwardea5930::Forward
#include "LeafForwardea5930.h"
extern "C" void* leaf_target(void*);
void* LeafForwardea5930::Forward() { return leaf_target(this); }
