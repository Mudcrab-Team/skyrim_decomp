// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NavMesh: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4bc4b0: GUESS(low); provisional member name
// 0x4bc4b0 NavMesh::Function4bc4b0
// CI hash: 0x4bc4b0 ?Function4bc4b0@NavMesh@@QEAAXPEAUTransform4bc4b0@@@Z
#include "NavMesh_4bc4b0.h"

// Guess: Transform all navigation vertices and refresh dependent data.
void NavMesh::Function4bc4b0(Transform4bc4b0* transform)
{
    if (count) {
        auto* current = vertices;
        auto* end = vertices + count;
        while (current != end) {
            Point4bc4b0 scaled = {current->x * transform->scale, current->y * transform->scale, current->z * transform->scale};
            transform->Apply(&transform->translation, true, &scaled, current);
            ++current;
        }
    }
    data.Update();
}
