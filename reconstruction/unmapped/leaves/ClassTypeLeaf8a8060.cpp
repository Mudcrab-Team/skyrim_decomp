// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8a8060 ClassTypeLeaf8a8060::QClassType
// CI hash: 0x8a8060 ?QClassType@ClassTypeLeaf8a8060@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8a8060.h"
const BSFixedString & ClassTypeLeaf8a8060::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8a8060");
    return typeString;
}
