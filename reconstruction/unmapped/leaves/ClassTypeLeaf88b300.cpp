// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x88b300 ClassTypeLeaf88b300::QClassType
// CI hash: 0x88b300 ?QClassType@ClassTypeLeaf88b300@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf88b300.h"
const BSFixedString & ClassTypeLeaf88b300::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf88b300");
    return typeString;
}
