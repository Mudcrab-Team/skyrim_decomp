// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x88b270 ClassTypeLeaf88b270::QClassType
// CI hash: 0x88b270 ?QClassType@ClassTypeLeaf88b270@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf88b270.h"
const BSFixedString & ClassTypeLeaf88b270::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf88b270");
    return typeString;
}
