// p202_91265cc5: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x4f5b00 PathingRequestFlyAction::Function4f5b00
#include "PathingRequestFlyAction.h"
using namespace p202_91265cc5;
std::uint32_t PathingRequestFlyAction::Function4f5b00()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
