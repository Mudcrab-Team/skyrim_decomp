// Source exposure: binary-analysis; no external implementation source reused.
// Code origin: original reconstruction from binary analysis.
// Origin: storage-adapter-initializer v2
// 0x1c7860 StorageInit1c7860::initialize
#include "StorageInit1c7860.h"
unsigned StorageInit1c7860::initialize(void* object)
{
    Adapter adapter(object);
    unsigned& count = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 16);
    unsigned& storage = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 24);
    return storage_helper(&storage, &adapter, count, 4);
}
