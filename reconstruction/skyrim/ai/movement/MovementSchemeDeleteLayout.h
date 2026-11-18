// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: interface and reference-count declarations adapted from the pinned public headers; derived scalar declarations originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSTEvent.h and BSIntrusiveRefCounted.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementSchemeRefCount: GUESS(medium) STANDIN; public reference-count alias.
// _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct MovementSchemeRefCount { mutable volatile std::uint32_t _refCount; };
// MovementSchemeDeleteLayout: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout(); };
static_assert(sizeof(MovementSchemeDeleteLayout)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout1: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout1 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout1(); };
static_assert(sizeof(MovementSchemeDeleteLayout1)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout1, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout2: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout2 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout2(); };
static_assert(sizeof(MovementSchemeDeleteLayout2)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout2, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout3: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout3 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout3(); };
static_assert(sizeof(MovementSchemeDeleteLayout3)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout3, _refCount)==8, "reference-count subobject");
}
