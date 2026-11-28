// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x11b8320 Function11b8320
// Adapted bodies: none
#include "FreeFunction_11b8320.h"

// Serializes position, optional subobject, optional identifier, and trailing scalar fields to writer.
void Function11b8320(const Data_11b8320* data, Writer_11b8320* writer)
{
    writer->WriteFloat(data->x);
    writer->WriteFloat(data->y);
    writer->WriteFloat(data->z);
    if (data->sub != nullptr) {
        std::uint32_t typeId = data->sub->GetTypeId();
        writer->WriteUInt32(typeId);
        data->sub->Write(writer);
    } else {
        writer->WriteUInt32(0);
    }
    std::uint32_t id = 0;
    if (data->idPtr != nullptr) {
        id = *data->idPtr;
    }
    writer->WriteId(id);
    writer->WriteUInt16(data->u28);
    writer->WriteUInt8(data->u2a);
    writer->WriteUInt8(data->u2b);
}
