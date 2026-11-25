// Source exposure: mixed. Drafted from local instruction listings of the
// Code origin: Stamped as a twin of matched 0xf01650 (bssystem/BSResourceNiBinaryStream): source copied, names replaced by placeholders.
// pinned image, with names from CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold at the pinned checkouts.
// 0xab1ca0 Ownerab1ca0::tell
#include "Ownerab1ca0.h"

Ownerab1ca0::Ownerab1ca0()
{
	stream = nullptr;
	buffer = nullptr;
	streamPos = 0;
	lastError = 0;
}

// guess: same compiled code as matched 0xf01650 apart from relocated fields; its role here is not established.
std::uint32_t Ownerab1ca0::tell() const
{
	return streamPos;
}
