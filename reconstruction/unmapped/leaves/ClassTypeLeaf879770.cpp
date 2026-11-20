// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x879770 ClassTypeLeaf879770::QClassType
// CI hash: 0x879770 ?QClassType@ClassTypeLeaf879770@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf879770.h"
const BSFixedString & ClassTypeLeaf879770::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf879770");
    return typeString;
}
