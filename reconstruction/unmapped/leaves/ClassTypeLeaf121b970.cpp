// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x121b970 ClassTypeLeaf121b970::QClassType
// CI hash: 0x121b970 ?QClassType@ClassTypeLeaf121b970@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf121b970.h"
const BSFixedString & ClassTypeLeaf121b970::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf121b970");
    return typeString;
}
