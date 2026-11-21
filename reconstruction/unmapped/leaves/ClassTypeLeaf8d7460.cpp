// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8d7460 ClassTypeLeaf8d7460::QClassType
// CI hash: 0x8d7460 ?QClassType@ClassTypeLeaf8d7460@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf8d7460.h"
const BSFixedString & ClassTypeLeaf8d7460::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf8d7460");
    return typeString;
}
