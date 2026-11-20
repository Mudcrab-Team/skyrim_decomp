// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x87cd80 ClassTypeLeaf87cd80::QClassType
// CI hash: 0x87cd80 ?QClassType@ClassTypeLeaf87cd80@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf87cd80.h"
const BSFixedString & ClassTypeLeaf87cd80::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf87cd80");
    return typeString;
}
