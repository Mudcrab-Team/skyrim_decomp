// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0x1290ca0, 56 bytes: AsyncOperationProxy scalar deleting destructor; the member destructor stays out of line and the class stores no vftable of its own.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x1290ca0 ??_GAsyncOperationProxy@@UEAAPEAXI@Z
#include "AsyncOperationProxy_1290ca0.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
AsyncOperationProxy::AsyncOperationProxy()
{
}
