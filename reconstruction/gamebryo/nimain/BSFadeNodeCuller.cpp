// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction written for this project from the local function pack (listing only, no copied body); declarations reuse community names from the pinned checkouts named below; Function1555fc0: written for this reconstruction from the listing and the header declarations; names from the header, the setter role is a guess
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// 0x1555fd0 BSFadeNodeCuller::Process1
// 0x1555fc0 BSFadeNodeCuller::Function1555fc0
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BSFadeNodeCuller.h"

// BSFadeNodeCuller::Function1555fc0: GUESS(low); name and role; stores the argument into the camera slot
void BSFadeNodeCuller::Function1555fc0(const NiCamera* a_camera)
{
	camera = a_camera;
}

// BSFadeNodeCuller::Process1: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); declaration
// only, compared at its own address elsewhere.
void BSFadeNodeCuller::Process1(NiAVObject* a_object, std::int32_t a_arg2)
{
	BSFadeNode* fadeNode = a_object->AsFadeNode();
	if (fadeNode == nullptr) {
		return;
	}

	fadeNode->flags |= static_cast<std::uint32_t>(NiAVObject::Flag::kMeshLOD);

	const float         radius = fadeNode->worldBound.radius;
	std::uint32_t       index = 0;
	const std::uint32_t flags = fadeNode->flags;
	const float         centerY = fadeNode->worldBound.center.y;
	const float         centerX = fadeNode->worldBound.center.x;
	const float         centerZ = fadeNode->worldBound.center.z;

	do {
		const NiPlane& plane = planes.cullingPlanes[index];
		const float    distance =
            centerX * plane.normal.x + centerY * plane.normal.y + centerZ * plane.normal.z - plane.constant;
		if (distance > -radius) {
			++index;
		} else {
			break;
		}
	} while (index < static_cast<std::uint32_t>(NiFrustumPlanes::kTotal));

	if (index != static_cast<std::uint32_t>(NiFrustumPlanes::kTotal)) {
		fadeNode->flags = flags | static_cast<std::uint32_t>(NiAVObject::Flag::kNoDismember);
	} else {
		fadeNode->flags = flags & ~static_cast<std::uint32_t>(NiAVObject::Flag::kNoDismember);
	}
}
