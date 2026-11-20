// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x1222350 ClassTypeLeaf1222350::QClassType
// CI hash: 0x1222350 ?QClassType@ClassTypeLeaf1222350@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf1222350.h"
const BSFixedString & ClassTypeLeaf1222350::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf1222350");
    return typeString;
}
