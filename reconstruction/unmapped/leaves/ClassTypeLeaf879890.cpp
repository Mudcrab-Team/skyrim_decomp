// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x879890 ClassTypeLeaf879890::QClassType
// CI hash: 0x879890 ?QClassType@ClassTypeLeaf879890@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf879890.h"
const BSFixedString & ClassTypeLeaf879890::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf879890");
    return typeString;
}
