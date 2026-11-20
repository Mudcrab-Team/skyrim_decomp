// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7aad00 ClassTypeLeaf7aad00::QClassType
// CI hash: 0x7aad00 ?QClassType@ClassTypeLeaf7aad00@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf7aad00.h"
const BSFixedString & ClassTypeLeaf7aad00::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf7aad00");
    return typeString;
}
