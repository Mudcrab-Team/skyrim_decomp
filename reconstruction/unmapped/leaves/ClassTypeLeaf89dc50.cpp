// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x89dc50 ClassTypeLeaf89dc50::QClassType
// CI hash: 0x89dc50 ?QClassType@ClassTypeLeaf89dc50@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf89dc50.h"
const BSFixedString & ClassTypeLeaf89dc50::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf89dc50");
    return typeString;
}
