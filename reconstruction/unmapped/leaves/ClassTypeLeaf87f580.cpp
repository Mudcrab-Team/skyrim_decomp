// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x87f580 ClassTypeLeaf87f580::QClassType
// CI hash: 0x87f580 ?QClassType@ClassTypeLeaf87f580@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf87f580.h"
const BSFixedString & ClassTypeLeaf87f580::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf87f580");
    return typeString;
}
