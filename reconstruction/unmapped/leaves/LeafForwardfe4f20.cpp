// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe4f20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe4f20 LeafForwardfe4f20::Forward
#include "LeafForwardfe4f20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe4f20::Forward() { return leaf_target(this); }
