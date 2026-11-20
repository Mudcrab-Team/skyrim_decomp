// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbbb370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbbb370 LeafForwardbbb370::Forward
#include "LeafForwardbbb370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbbb370::Forward() { return leaf_target(this); }
