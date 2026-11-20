// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1085b20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1085b20 LeafForward1085b20::Forward
#include "LeafForward1085b20.h"
extern "C" void* leaf_target(void*);
void* LeafForward1085b20::Forward() { return leaf_target(this); }
