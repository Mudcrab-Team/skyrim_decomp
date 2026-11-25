// Source exposure: mixed. Drafted from local instruction listings of the
// Code origin: Stamped as a twin of matched 0xf01650 (bssystem/BSResourceNiBinaryStream): source copied, names replaced by placeholders.
// pinned image, with names from CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold at the pinned checkouts.
// 0xcb89b0 Ownercb89b0::tell
#include "Ownercb89b0.h"

Ownercb89b0::Ownercb89b0()
{
	stream = nullptr;
	buffer = nullptr;
	streamPos = 0;
	lastError = 0;
}

// guess: same compiled code as matched 0xf01650 apart from relocated fields; its role here is not established.
std::uint32_t Ownercb89b0::tell() const
{
	return streamPos;
}
