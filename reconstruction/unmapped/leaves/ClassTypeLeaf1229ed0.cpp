// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x1229ed0 ClassTypeLeaf1229ed0::QClassType
// CI hash: 0x1229ed0 ?QClassType@ClassTypeLeaf1229ed0@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf1229ed0.h"
const BSFixedString & ClassTypeLeaf1229ed0::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf1229ed0");
    return typeString;
}
