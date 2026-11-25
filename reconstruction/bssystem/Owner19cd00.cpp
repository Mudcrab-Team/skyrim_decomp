// Source exposure: mixed. Drafted from local instruction listings of the
// Code origin: Stamped as a twin of matched 0xf01650 (bssystem/BSResourceNiBinaryStream): source copied, names replaced by placeholders.
// pinned image, with names from CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold at the pinned checkouts.
// 0x19cd00 Owner19cd00::tell
#include "Owner19cd00.h"

Owner19cd00::Owner19cd00()
{
	stream = nullptr;
	buffer = nullptr;
	streamPos = 0;
	lastError = 0;
}

// guess: same compiled code as matched 0xf01650 apart from relocated fields; its role here is not established.
std::uint32_t Owner19cd00::tell() const
{
	return streamPos;
}
