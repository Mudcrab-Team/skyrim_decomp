// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11ca850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11ca850 LeafForward11ca850::Forward
#include "LeafForward11ca850.h"
extern "C" void* leaf_target(void*);
void* LeafForward11ca850::Forward() { return leaf_target(this); }
