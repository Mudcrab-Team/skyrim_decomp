// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x88af10 ClassTypeLeaf88af10::QClassType
// CI hash: 0x88af10 ?QClassType@ClassTypeLeaf88af10@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf88af10.h"
const BSFixedString & ClassTypeLeaf88af10::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf88af10");
    return typeString;
}
