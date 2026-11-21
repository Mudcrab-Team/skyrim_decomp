// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x55f780 ClassTypeLeaf55f780::QClassType
// CI hash: 0x55f780 ?QClassType@ClassTypeLeaf55f780@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf55f780.h"
const BSFixedString & ClassTypeLeaf55f780::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf55f780");
    return typeString;
}
