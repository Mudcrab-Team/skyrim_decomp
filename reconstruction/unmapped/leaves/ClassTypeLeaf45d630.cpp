// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x45d630 ClassTypeLeaf45d630::QClassType
// CI hash: 0x45d630 ?QClassType@ClassTypeLeaf45d630@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf45d630.h"
const BSFixedString & ClassTypeLeaf45d630::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf45d630");
    return typeString;
}
