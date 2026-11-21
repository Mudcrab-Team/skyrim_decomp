// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x1224a00 ClassTypeLeaf1224a00::QClassType
// CI hash: 0x1224a00 ?QClassType@ClassTypeLeaf1224a00@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf1224a00.h"
const BSFixedString & ClassTypeLeaf1224a00::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf1224a00");
    return typeString;
}
