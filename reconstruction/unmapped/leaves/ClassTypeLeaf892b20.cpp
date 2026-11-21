// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x892b20 ClassTypeLeaf892b20::QClassType
// CI hash: 0x892b20 ?QClassType@ClassTypeLeaf892b20@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf892b20.h"
const BSFixedString & ClassTypeLeaf892b20::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf892b20");
    return typeString;
}
