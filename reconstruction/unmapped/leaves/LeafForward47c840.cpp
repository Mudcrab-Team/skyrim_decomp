// Source exposure: binary-analysis; no external implementation reused.
// LeafForward47c840, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x47c840 LeafForward47c840::Forward
#include "LeafForward47c840.h"
extern "C" void* leaf_target(void*);
void* LeafForward47c840::Forward() { return leaf_target(this); }
