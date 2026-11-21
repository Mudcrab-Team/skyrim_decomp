// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x4653a0 ClassTypeLeaf4653a0::QClassType
// CI hash: 0x4653a0 ?QClassType@ClassTypeLeaf4653a0@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf4653a0.h"
const BSFixedString & ClassTypeLeaf4653a0::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf4653a0");
    return typeString;
}
