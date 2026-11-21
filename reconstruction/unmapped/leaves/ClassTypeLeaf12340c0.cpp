// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x12340c0 ClassTypeLeaf12340c0::QClassType
// CI hash: 0x12340c0 ?QClassType@ClassTypeLeaf12340c0@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf12340c0.h"
const BSFixedString & ClassTypeLeaf12340c0::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf12340c0");
    return typeString;
}
