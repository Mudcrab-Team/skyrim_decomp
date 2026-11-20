// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x435cb0 BSFaceGenModel::~BSFaceGenModel
#include "BSFaceGenModel.h"
BSFaceGenModel::BSFaceGenModel() {}
BSFaceGenModel::~BSFaceGenModel() { if(modelMeshData.data) { auto* old=modelMeshData.data; modelMeshData.data=nullptr; ReleaseFaceMesh(old); } }

