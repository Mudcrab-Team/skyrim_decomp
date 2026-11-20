// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x89db30 ClassTypeLeaf89db30::QClassType
// CI hash: 0x89db30 ?QClassType@ClassTypeLeaf89db30@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf89db30.h"
const BSFixedString & ClassTypeLeaf89db30::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf89db30");
    return typeString;
}
