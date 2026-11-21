// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x11cd050 ClassTypeLeaf11cd050::QClassType
// CI hash: 0x11cd050 ?QClassType@ClassTypeLeaf11cd050@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf11cd050.h"
const BSFixedString & ClassTypeLeaf11cd050::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf11cd050");
    return typeString;
}
