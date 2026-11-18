// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157bd70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157bd70 LeafForward157bd70::Forward
#include "LeafForward157bd70.h"
extern "C" void* leaf_target(void*);
void* LeafForward157bd70::Forward() { return leaf_target(this); }
