// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1175400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1175400 LeafForward1175400::Forward
#include "LeafForward1175400.h"
extern "C" void* leaf_target(void*);
void* LeafForward1175400::Forward() { return leaf_target(this); }
