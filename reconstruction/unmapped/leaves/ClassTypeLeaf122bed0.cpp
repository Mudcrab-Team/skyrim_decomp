// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x122bed0 ClassTypeLeaf122bed0::QClassType
// CI hash: 0x122bed0 ?QClassType@ClassTypeLeaf122bed0@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf122bed0.h"
const BSFixedString & ClassTypeLeaf122bed0::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf122bed0");
    return typeString;
}
