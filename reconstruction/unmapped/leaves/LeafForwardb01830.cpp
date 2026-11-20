// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb01830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb01830 LeafForwardb01830::Forward
#include "LeafForwardb01830.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb01830::Forward() { return leaf_target(this); }
