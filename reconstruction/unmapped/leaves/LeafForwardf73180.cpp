// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73180 LeafForwardf73180::Forward
#include "LeafForwardf73180.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73180::Forward() { return leaf_target(this); }
