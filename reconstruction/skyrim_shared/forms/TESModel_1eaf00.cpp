// TESModel, sub, Update, FixedString: GUESS(low)
// model, textures, addons, numTextures, numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix declarations adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1eaf00 TESModel::sub

#include "TESModel_1eaf00.h"
void TESModel::sub(TESModel* model, void* arg) { if (model) Update(&model->textures, &model->numTextures, &model->addons, &model->numAddons, arg); }
