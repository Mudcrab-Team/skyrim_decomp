// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0xdf09f0 GFxDisplayContext::RestoreDisplayState
#include "GFxDisplayContext_df09f0.h"

// Restores saved 3D renderer matrices and transform pointers onto the display context.
void GFxDisplayContext::RestoreDisplayState(const GFxDisplayState* a_state)
{
    if (has3DWorld)
    {
        renderConfig->renderer->SetWorld3D(a_state->world3D);
    }
    if (!unk80)
    {
        if (a_state->view3D)
        {
            renderConfig->renderer->SetView3D(a_state->view3D);
        }
        if (a_state->perspective3D)
        {
            renderConfig->renderer->SetPerspective3D(a_state->perspective3D);
        }
    }
    cxform = a_state->cxform;
    matrix = a_state->matrix;
    world3D = a_state->world3D;
    perspective3D = a_state->perspective3D;
    view3D = a_state->view3D;
    has3DWorld = a_state->has3DWorld;
}
