// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x881c10 ClassTypeLeaf881c10::QClassType
// CI hash: 0x881c10 ?QClassType@ClassTypeLeaf881c10@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf881c10.h"
const BSFixedString & ClassTypeLeaf881c10::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf881c10");
    return typeString;
}
