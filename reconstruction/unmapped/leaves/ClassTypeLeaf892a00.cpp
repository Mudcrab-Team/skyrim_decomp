// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x892a00 ClassTypeLeaf892a00::QClassType
// CI hash: 0x892a00 ?QClassType@ClassTypeLeaf892a00@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf892a00.h"
const BSFixedString & ClassTypeLeaf892a00::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf892a00");
    return typeString;
}
