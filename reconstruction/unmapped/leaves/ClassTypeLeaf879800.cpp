// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x879800 ClassTypeLeaf879800::QClassType
// CI hash: 0x879800 ?QClassType@ClassTypeLeaf879800@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf879800.h"
const BSFixedString & ClassTypeLeaf879800::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf879800");
    return typeString;
}
