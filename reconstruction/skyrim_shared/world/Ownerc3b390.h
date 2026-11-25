// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x2709b0 (skyrim_shared/world/TESGrass): source copied, names replaced by placeholders.
// Names and slot order follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT): include/RE/T/TESGrass.h and the vftables of the pinned image; the powerof3 fork (GPL-3.0) declares the same names.
// BaseFormComponent, TESBoundObject, TESModel: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT);
// Ownerc3b390: GUESS(low) STANDIN
// Ownerc3b390, Ownerc3b390::~Ownerc3b390, Ownerc3b390::InitializeData, Ownerc3b390::Load, Ownerc3b390::InitItemImpl, Ownerc3b390::GetDensity, Ownerc3b390::SetDensity, Ownerc3b390::GetMinSlopeDegrees, Ownerc3b390::SetMinSlopeDegrees, Ownerc3b390::GetMaxSlopeDegrees, Ownerc3b390::SetMaxSlopeDegrees, Ownerc3b390::GetMinSlope, Ownerc3b390::GetMaxSlope, Ownerc3b390::GetDistanceFromWaterLevel, Ownerc3b390::SetDistanceFromWaterLevel, Ownerc3b390::GetUnderwaterState, Ownerc3b390::SetUnderwaterState, Ownerc3b390::GetPositionRange, Ownerc3b390::SetPositionRange, Ownerc3b390::GetHeightRange, Ownerc3b390::SetHeightRange, Ownerc3b390::GetColorRange, Ownerc3b390::SetColorRange, Ownerc3b390::GetWavePeriod, Ownerc3b390::SetWavePeriod, Ownerc3b390::GetVertexLighting, Ownerc3b390::SetVertexLighting, Ownerc3b390::GetUniformScaling, Ownerc3b390::SetUniformScaling, Ownerc3b390::GetFitToSlope, Ownerc3b390::SetFitToSlope, GRASS_DATA, unk0C, heightRange, colorRange, data: GUESS(low) STANDIN
#pragma once
#include "TESGrass.h"

// Other RTTI bases (not declared here; their vftable pointers lie inside the members): .?AVTESModel@@
class Ownerc3b390 : public ::TESBoundObject, public ::TESModel
{
public:
	enum class GRASS_WATER_STATE : std::uint32_t
	{
		kAboveOnlyAtLeast = 0,
		kAboveOnlyAtMost = 1,
		kBelowOnlyAtLeast = 2,
		kBelowOnlyAtMost = 3,
		kBothAtLeast = 4,
		kBothAtMost = 5,
		kBothAtMostAbove = 6,
		kBothAtMostBelow = 7
	};

	// community declaration: virtual ~BaseFormComponent();
	Ownerc3b390();
	~Ownerc3b390() override;  // 00
	// community declaration: virtual void InitializeData();
	void InitializeData() override;  // 04
	// community declaration: virtual bool Load(TESFile* a_mod);
	void Load() override;  // 06
	// community declaration: virtual void InitItemImpl();
	void InitItemImpl() override;  // 13
	// community declaration: virtual std::uint8_t GetDensity() const;
	virtual std::uint8_t GetDensity() const;  // 53
	// community declaration: virtual bool SetDensity(std::uint8_t a_density);
	virtual void SetDensity();  // 54
	// community declaration: virtual std::uint8_t GetMinSlopeDegrees() const;
	virtual std::uint8_t GetMinSlopeDegrees() const;  // 55
	// community declaration: virtual bool SetMinSlopeDegrees(std::uint8_t a_minSlope);
	virtual void SetMinSlopeDegrees();  // 56
	// community declaration: virtual std::uint8_t GetMaxSlopeDegrees() const;
	virtual std::uint8_t GetMaxSlopeDegrees() const;  // 57
	// community declaration: virtual bool SetMaxSlopeDegrees(std::uint8_t a_maxSlope);
	virtual void SetMaxSlopeDegrees();  // 58
	// community declaration: virtual float GetMinSlope() const;
	virtual float GetMinSlope() const;  // 59
	// community declaration: virtual float GetMaxSlope() const;
	virtual float GetMaxSlope() const;  // 5A
	// community declaration: virtual std::uint16_t GetDistanceFromWaterLevel() const;
	virtual std::uint16_t GetDistanceFromWaterLevel() const;  // 5B
	// community declaration: virtual void SetDistanceFromWaterLevel(std::uint16_t a_unitsFromWater);
	virtual void SetDistanceFromWaterLevel(std::uint16_t a_unitsFromWater);  // 5C
	// community declaration: virtual GRASS_WATER_STATE GetUnderwaterState() const;
	virtual GRASS_WATER_STATE GetUnderwaterState() const;  // 5D
	// community declaration: virtual void SetUnderwaterState(GRASS_WATER_STATE a_waterState);
	virtual void SetUnderwaterState(GRASS_WATER_STATE a_waterState);  // 5E
	// community declaration: virtual float GetPositionRange() const;
	virtual void GetPositionRange();  // 5F
	// community declaration: virtual bool SetPositionRange(float a_positionRange);
	virtual void SetPositionRange();  // 60
	// community declaration: virtual float GetHeightRange() const;
	virtual float GetHeightRange() const;  // 61
	// community declaration: virtual bool SetHeightRange(float a_heightRange);
	virtual void SetHeightRange();  // 62
	// community declaration: virtual float GetColorRange() const;
	virtual float GetColorRange() const;  // 63
	// community declaration: virtual bool SetColorRange(float a_colorRange);
	virtual void SetColorRange();  // 64
	// community declaration: virtual float GetWavePeriod() const;
	virtual void GetWavePeriod();  // 65
	// community declaration: virtual bool SetWavePeriod(float a_wavePeriod);
	virtual void SetWavePeriod();  // 66
	// community declaration: virtual bool GetVertexLighting() const;
	virtual void GetVertexLighting();  // 67
	// community declaration: virtual void SetVertexLighting(bool a_set);
	virtual void SetVertexLighting();  // 68
	// community declaration: virtual bool GetUniformScaling() const;
	virtual void GetUniformScaling();  // 69
	// community declaration: virtual void SetUniformScaling(bool a_set);
	virtual void SetUniformScaling();  // 6A
	// community declaration: virtual bool GetFitToSlope() const;
	virtual void GetFitToSlope();  // 6B
	// community declaration: virtual void SetFitToSlope(bool a_set);
	virtual void SetFitToSlope();  // 6C

	struct GRASS_DATA
	{
		std::int8_t   density;                 // 00
		std::uint8_t  minSlopeDegrees;         // 01
		std::uint8_t  maxSlopeDegrees;         // 02
		std::uint8_t  pad03;                   // 03
		std::uint16_t distanceFromWaterLevel;  // 04
		std::uint16_t pad06;                   // 06
		GRASS_WATER_STATE underwater;          // 08
		std::uint8_t  unk0C[0x4];  // 0C
		float heightRange;  // 10
		float colorRange;  // 14
		std::uint8_t unk18[0x20 - 0x18];  // 18
	};
	static_assert((sizeof(GRASS_DATA) == 0x20), "layout");

	GRASS_DATA data;  // 58
};
static_assert((sizeof(Ownerc3b390) == 0x78), "layout");
