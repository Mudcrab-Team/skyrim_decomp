// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x881b80 ClassTypeLeaf881b80::QClassType
// CI hash: 0x881b80 ?QClassType@ClassTypeLeaf881b80@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf881b80.h"
const BSFixedString & ClassTypeLeaf881b80::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf881b80");
    return typeString;
}
