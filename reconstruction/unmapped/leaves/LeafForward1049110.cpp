// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1049110, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1049110 LeafForward1049110::Forward
#include "LeafForward1049110.h"
extern "C" void* leaf_target(void*);
void* LeafForward1049110::Forward() { return leaf_target(this); }
