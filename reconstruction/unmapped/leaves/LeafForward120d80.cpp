// Source exposure: binary-analysis; no external implementation reused.
// LeafForward120d80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x120d80 LeafForward120d80::Forward
#include "LeafForward120d80.h"
extern "C" void* leaf_target(void*);
void* LeafForward120d80::Forward() { return leaf_target(this); }
