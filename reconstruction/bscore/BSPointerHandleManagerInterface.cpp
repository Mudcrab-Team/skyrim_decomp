// Source exposure: mixed. Drafted by claude-sonnet-5-5 from a local listing of the pinned image
// with types from the header beside this file.
// 0x240f50 BSPointerHandleManagerInterface::GetHandle
#include "BSPointerHandleManagerInterface.h"

template <class T, class Manager>
BSPointerHandle<T> BSPointerHandleManagerInterface<T, Manager>::GetHandle(T* a_ptr)
{
    BSPointerHandle<T> handle;
    if (a_ptr && (a_ptr->flags & 0x3ff) == 0) {
        handle.native_handle = kNullHandle;
    } else {
        CreateRefHandle(handle, a_ptr);
    }
    return handle;
}

// Explicit instantiation so the member is emitted as an external symbol in this unit.
template class BSPointerHandleManagerInterface<Actor, BSPointerHandleManager>;
