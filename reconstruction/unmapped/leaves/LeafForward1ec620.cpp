// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1ec620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1ec620 LeafForward1ec620::Forward
#include "LeafForward1ec620.h"
extern "C" void* leaf_target(void*);
void* LeafForward1ec620::Forward() { return leaf_target(this); }
