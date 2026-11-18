// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// BSMultiIndexTriShape, BSMultiIndexTriShape::AsMultiIndexTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class BSMultiIndexTriShape {
public:
    virtual ~BSMultiIndexTriShape();

    // The virtual slot order is not compared here; only the body below is.
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();  // compared: 0x1575450
};
