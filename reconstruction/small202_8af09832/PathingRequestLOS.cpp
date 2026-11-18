// p202_8af09832: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x4f82f0 PathingRequestLOS::Function4f82f0
#include "PathingRequestLOS.h"
using namespace p202_8af09832;
std::uint32_t PathingRequestLOS::Function4f82f0()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
