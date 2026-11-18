// p202_c5cd5b12: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x4f29d0 PathingRequestClosestGoal::Function4f29d0
#include "PathingRequestClosestGoal.h"
using namespace p202_c5cd5b12;
std::uint32_t PathingRequestClosestGoal::Function4f29d0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
