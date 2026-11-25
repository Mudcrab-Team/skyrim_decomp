// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0xfc8100, 74 bytes: QueuedNamedFile scalar deleting destructor; the member and base destructors stay out of line.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xfc8100 ??_GQueuedNamedFile@@UEAAPEAXI@Z
#include "QueuedNamedFile_fc8100.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
QueuedNamedFile::QueuedNamedFile()
{
}
