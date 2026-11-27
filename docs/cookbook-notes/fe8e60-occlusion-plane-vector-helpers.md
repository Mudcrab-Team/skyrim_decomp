# 0xfe8e60 BSOcclusionPlane::IntersectsPlanes

<!-- tags: construct/float, wall/inlining, wall/register-schedule -->

- Function: 0xfe8e60 BSOcclusionPlane::IntersectsPlanes
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 363/363 bytes, local comparator pass
- Attempts: 4

## What differed

An earlier matching draft used a `const volatile NiPoint3&` binding to force the vertical axis components to be loaded before the horizontal dot product. Removing `volatile` caused the compiler to defer the axis loads and changed both register allocation and the dot-product schedule.

## Spellings tried that did not help

- Loading the three floats into separate scalar locals after the horizontal check: the compiler scheduled the loads after the branch.
- Aggregate-initializing `NiPoint3` with brace-init inside `operator-` and `GetRow` without a three-float constructor: MSVC 19.16 left `operator-` out of line as an unbound call.

## Spelling that fixed it

Give `NiPoint3` a defaulted default constructor plus a three-float constructor, define inline `NiMatrix3::GetRow`, `NiPoint3::operator-`, and `NiPoint3::Dot`, and compute `vertical = rotation.GetRow(2)`, `delta = origin - translation`, and `horizontal = rotation.GetRow(1)` in that order under `o2-fpfast-root-includes.json`. The compiler inlines all three helpers and schedules the loads identically without `volatile`.
