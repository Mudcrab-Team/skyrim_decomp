// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x87cf30 ClassTypeLeaf87cf30::QClassType
// CI hash: 0x87cf30 ?QClassType@ClassTypeLeaf87cf30@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf87cf30.h"
const BSFixedString & ClassTypeLeaf87cf30::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf87cf30");
    return typeString;
}
