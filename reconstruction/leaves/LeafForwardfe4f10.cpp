// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe4f10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe4f10 LeafForwardfe4f10::Forward
#include "LeafForwardfe4f10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe4f10::Forward() { return leaf_target(this); }
