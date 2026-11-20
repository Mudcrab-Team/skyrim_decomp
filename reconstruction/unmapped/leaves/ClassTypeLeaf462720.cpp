// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x462720 ClassTypeLeaf462720::QClassType
// CI hash: 0x462720 ?QClassType@ClassTypeLeaf462720@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf462720.h"
const BSFixedString & ClassTypeLeaf462720::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf462720");
    return typeString;
}
