// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x881a60 ClassTypeLeaf881a60::QClassType
// CI hash: 0x881a60 ?QClassType@ClassTypeLeaf881a60@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf881a60.h"
const BSFixedString & ClassTypeLeaf881a60::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf881a60");
    return typeString;
}
