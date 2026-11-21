// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DepthProperties; size 0x10
#pragma once
struct DepthProperties {
    float reflections;
    float refraction;
    float normals;
    float specularLighting;
};
static_assert(sizeof(DepthProperties) == 16, "DepthProperties layout differs from the PDB");
