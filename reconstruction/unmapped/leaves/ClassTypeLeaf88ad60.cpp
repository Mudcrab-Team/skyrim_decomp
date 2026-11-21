// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x88ad60 ClassTypeLeaf88ad60::QClassType
// CI hash: 0x88ad60 ?QClassType@ClassTypeLeaf88ad60@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf88ad60.h"
const BSFixedString & ClassTypeLeaf88ad60::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf88ad60");
    return typeString;
}
