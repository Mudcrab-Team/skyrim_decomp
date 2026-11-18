// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe4230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe4230 LeafForwardfe4230::Forward
#include "LeafForwardfe4230.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe4230::Forward() { return leaf_target(this); }
