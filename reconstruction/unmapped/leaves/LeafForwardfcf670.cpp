// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfcf670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfcf670 LeafForwardfcf670::Forward
#include "LeafForwardfcf670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfcf670::Forward() { return leaf_target(this); }
