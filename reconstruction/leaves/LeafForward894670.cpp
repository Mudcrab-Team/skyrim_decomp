// Source exposure: binary-analysis; no external implementation reused.
// LeafForward894670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x894670 LeafForward894670::Forward
#include "LeafForward894670.h"
extern "C" void* leaf_target(void*);
void* LeafForward894670::Forward() { return leaf_target(this); }
