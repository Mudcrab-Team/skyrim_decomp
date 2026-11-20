// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8b1650 ClassTypeLeaf8b1650::QClassType
// CI hash: 0x8b1650 ?QClassType@ClassTypeLeaf8b1650@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8b1650.h"
const BSFixedString & ClassTypeLeaf8b1650::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8b1650");
    return typeString;
}
