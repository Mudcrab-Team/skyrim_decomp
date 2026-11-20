// Source exposure: mixed (binary-analysis shape; sibling-derived accessor pattern).
// Code origin: type-name accessor with a function-local static, adapted from the cited sibling body; class name is a placeholder.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.h:5
// QClassType, typeString: SIBLING(fo4-private@1b765c70, author-permission)
// ClassTypeLeaf87d0e0, BSFixedString, data: GUESS(low) STANDIN
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class ClassTypeLeaf87d0e0 { public: static const BSFixedString & QClassType();  // compared: 0x87d0e0
};
