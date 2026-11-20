// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// AddCellGrassTask::Run: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:76
// AddCellGrassTask, QueuedFile, IOTask, BSTask: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted from include/RE/A/AddCellGrassTask.h, include/RE/Q/QueuedFile.h, include/RE/I/IOTask.h and include/RE/B/BSTask.h.
// The declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// BGSGrassManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/B/BGSGrassManager.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESObjectCELL;
class BSTask { public: virtual ~BSTask(); int refCount; unsigned unknown0c; unsigned long long unknown10; };
class IOTask : public BSTask {};
class QueuedFile : public IOTask { public: unsigned long long unknown18; QueuedFile* parent; unsigned long long children, unknown30; };
class BGSGrassManager { public: void AddCellGrass(TESObjectCELL*, bool*); };
extern BGSGrassManager* grassManager;
class AddCellGrassTask : public QueuedFile { public: TESObjectCELL* cell; int x,y; bool cancel; void Run(); };
