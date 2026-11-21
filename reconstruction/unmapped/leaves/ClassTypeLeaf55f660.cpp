// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x55f660 ClassTypeLeaf55f660::QClassType
// CI hash: 0x55f660 ?QClassType@ClassTypeLeaf55f660@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf55f660.h"
const BSFixedString & ClassTypeLeaf55f660::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf55f660");
    return typeString;
}
