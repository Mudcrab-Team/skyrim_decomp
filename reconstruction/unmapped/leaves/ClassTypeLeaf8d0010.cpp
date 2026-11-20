// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8d0010 ClassTypeLeaf8d0010::QClassType
// CI hash: 0x8d0010 ?QClassType@ClassTypeLeaf8d0010@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8d0010.h"
const BSFixedString & ClassTypeLeaf8d0010::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8d0010");
    return typeString;
}
