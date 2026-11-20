// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x122cf50 ClassTypeLeaf122cf50::QClassType
// CI hash: 0x122cf50 ?QClassType@ClassTypeLeaf122cf50@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf122cf50.h"
const BSFixedString & ClassTypeLeaf122cf50::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf122cf50");
    return typeString;
}
