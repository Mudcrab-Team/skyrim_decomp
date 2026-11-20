// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the parent update and virtual bound refresh.
// 0xff3380 BSMultiBoundNode::UpdateUpwardPass
#include "BSMultiBoundNode_ff3380.h"

void BSMultiBoundNode::UpdateUpwardPass()
{
    NiNode::UpdateUpwardPass();
    UpdateWorldBound();
}
