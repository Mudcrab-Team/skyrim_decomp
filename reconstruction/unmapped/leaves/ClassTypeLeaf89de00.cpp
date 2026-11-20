// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x89de00 ClassTypeLeaf89de00::QClassType
// CI hash: 0x89de00 ?QClassType@ClassTypeLeaf89de00@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf89de00.h"
const BSFixedString & ClassTypeLeaf89de00::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf89de00");
    return typeString;
}
