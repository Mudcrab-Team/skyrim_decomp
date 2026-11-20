// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: adapted from the cited sibling body; the string literal is a placeholder, not the original class name.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// 0x121c660 ClassTypeLeaf121c660::QClassType
// CI hash: 0x121c660 ?QClassType@ClassTypeLeaf121c660@@SAAEBUBSFixedString@@XZ
#include "ClassTypeLeaf121c660.h"
const BSFixedString & ClassTypeLeaf121c660::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf121c660");
    return typeString;
}
