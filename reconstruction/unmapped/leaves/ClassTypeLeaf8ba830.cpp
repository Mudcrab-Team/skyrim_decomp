// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8ba830 ClassTypeLeaf8ba830::QClassType
// CI hash: 0x8ba830 ?QClassType@ClassTypeLeaf8ba830@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8ba830.h"
const BSFixedString & ClassTypeLeaf8ba830::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8ba830");
    return typeString;
}
