// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of scalar stream transfers and node save.
// 0xff3510 NiBinaryStream::ReadUInt32
// 0xff3590 NiStream::ReadUInt32
// 0xff35e0 NiStream::WriteUInt32
// 0xff2b50 BSMultiBoundNode::SaveBinary
#include "NiStream_ff3510.h"

void NiBinaryStream::ReadUInt32(std::uint32_t& output)
{
    std::uint32_t value;
    std::uint32_t size = sizeof(value);
    position += readFn(this, &value, sizeof(value), &size, 1);
    output = value;
}

void NiStream::ReadUInt32(std::uint32_t& output)
{
    iStr->ReadUInt32(output);
}

void NiStream::WriteUInt32(const std::uint32_t& value)
{
    auto* output = oStr;
    std::uint32_t size = sizeof(value);
    output->position += output->writeFn(output, &value, sizeof(value), &size, 1);
}

void BSMultiBoundNode::SaveBinary(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    stream.vtable->SaveLinkID(&stream, multiBound);
    auto* output = stream.oStr;
    std::uint32_t size = sizeof(cullingMode);
    output->position += output->writeFn(output, &cullingMode, sizeof(cullingMode), &size, 1);
}
