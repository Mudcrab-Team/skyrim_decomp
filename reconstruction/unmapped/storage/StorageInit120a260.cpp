// Source exposure: binary-analysis; no external implementation source reused.
// Code origin: original reconstruction from binary analysis.
// Origin: storage-adapter-initializer v2
// 0x120a260 StorageInit120a260::initialize
#include "StorageInit120a260.h"
unsigned StorageInit120a260::initialize(void* object)
{
    Adapter adapter(object);
    unsigned& count = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 16);
    unsigned& storage = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 24);
    return storage_helper(&storage, &adapter, count, 1);
}
