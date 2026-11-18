// Source exposure: binary-analysis; no external implementation reused.
// LeafForward836f10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x836f10 LeafForward836f10::Forward
#include "LeafForward836f10.h"
extern "C" void* leaf_target(void*);
void* LeafForward836f10::Forward() { return leaf_target(this); }
