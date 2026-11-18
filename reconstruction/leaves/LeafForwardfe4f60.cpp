// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe4f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe4f60 LeafForwardfe4f60::Forward
#include "LeafForwardfe4f60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe4f60::Forward() { return leaf_target(this); }
