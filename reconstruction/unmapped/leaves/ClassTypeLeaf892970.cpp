// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x892970 ClassTypeLeaf892970::QClassType
// CI hash: 0x892970 ?QClassType@ClassTypeLeaf892970@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf892970.h"
const BSFixedString & ClassTypeLeaf892970::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf892970");
    return typeString;
}
