// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of scalar stream transfers and node save. Stamped as a twin of matched 0xff35e0 (gamebryo/nimain/NiStream_ff3510): source copied, names replaced by placeholders.
// 0xf60230 Ownerf60230::Functionf60230
#include "Ownerf60230.h"

// guess: same compiled code as matched 0xff35e0 apart from relocated fields; its role here is not established.
void Ownerf60230::Functionf60230(const std::uint32_t& value)
{
    auto* output = oStr;
    std::uint32_t size = sizeof(value);
    output->position += output->writeFn(output, &value, sizeof(value), &size, 1);
}
