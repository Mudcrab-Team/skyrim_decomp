// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfab040, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfab040 LeafForwardfab040::Forward
#include "LeafForwardfab040.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfab040::Forward() { return leaf_target(this); }
