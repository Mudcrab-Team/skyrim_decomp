// Source exposure: mixed
// Code origin: DetachAll written from the target listing plus public declarations; KillAll adapted from the anonymous sibling and public declarations.
// GridCellArray, GridArray, GridCellArray::GetCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GridCellArray.h, include/RE/G/GridArray.h.
// GridCellArray::KillAll: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:140
// names: GUESS(low); unknown member and method names are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

class TESObjectCELL
{
public:
	static void KillStatics();
	// DetachAll: GUESS(low); no public name for the per-cell callee, placeholder name.
	void DetachAll();
};

class TESDataHandler
{
public:
	bool IsClearing();
};

extern TESDataHandler* dataHandler;

struct Point3
{
	float x;  // 00
	float y;  // 04
	float z;  // 08
};

class GridArray
{
public:
	virtual ~GridArray();  // 00
	// unknown08: GUESS(low); offset 08, value 1000, purpose unknown.
	unsigned unknown08;    // 08
	// unknown0c: GUESS(low); offset 0C, value 1000, purpose unknown.
	unsigned unknown0c;    // 0C
	unsigned length;       // 10 - takes value from uGridsToLoad
	// unknown14: GUESS(low); offset 14, no observed use.
	unsigned unknown14;    // 14
	void KillAll();
};

class GridCellArray : public GridArray
{
public:
	TESObjectCELL* GetCell(unsigned a_x, unsigned a_y) const
	{
		return (a_x < length && a_y < length) ? cells[(a_x * length) + a_y] : nullptr;
	}

	// GetCellSlot: GUESS(low); slot accessor, the target selects the element address and loads it after the join.
	// The loop bounds keep the null arm unreachable.
	TESObjectCELL** GetCellSlot(unsigned a_x, unsigned a_y) const
	{
		return (a_x < length && a_y < length) ? &cells[(a_x * length) + a_y] : nullptr;
	}

	TESObjectCELL** cells;     // 18 - allocated with 8 * numGrids * numGrids
	Point3 position;           // 20
	bool land3DAttached;       // 2C
	void KillAll();
	// DetachAll: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); the name is the GridArray base declaration, the body is independently written.
	void DetachAll();
};

static_assert(sizeof(GridArray) == 0x18, "GridArray size");

static_assert(sizeof(GridCellArray) == 0x30, "GridCellArray size");
