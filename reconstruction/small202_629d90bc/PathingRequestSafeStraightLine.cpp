// p202_629d90bc: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x4f93e0 PathingRequestSafeStraightLine::Function4f93e0
#include "PathingRequestSafeStraightLine.h"
using namespace p202_629d90bc;
std::uint32_t PathingRequestSafeStraightLine::Function4f93e0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
