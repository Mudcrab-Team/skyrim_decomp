// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8d2000 ClassTypeLeaf8d2000::QClassType
// CI hash: 0x8d2000 ?QClassType@ClassTypeLeaf8d2000@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8d2000.h"
const BSFixedString & ClassTypeLeaf8d2000::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8d2000");
    return typeString;
}
