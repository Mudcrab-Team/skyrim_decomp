// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, AppendPassToGeometryGroup, geometryGroups, GeometryGroup, BSRenderPass: CRASHLOGGER_PDB(59818@2026.10.24)
// AppendPass, flags: GUESS(low)
#pragma once

struct BSRenderPass;
class BSBatchRenderer
{
public:
    struct GeometryGroup
    {
        void AppendPass(BSRenderPass* pass, unsigned char flags);
    };

    void AppendPassToGeometryGroup(BSRenderPass* pass, int group, unsigned char flags);

    unsigned char unrecovered000[0x70];
    GeometryGroup* geometryGroups[16];
};
