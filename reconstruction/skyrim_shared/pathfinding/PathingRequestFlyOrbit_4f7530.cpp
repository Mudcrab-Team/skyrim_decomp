// p202_d73a89c2: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// 0x4f7530 PathingRequestFlyOrbit::Function4f7530
#include "PathingRequestFlyOrbit_4f7530.h"
using namespace p202_d73a89c2;
std::uint32_t PathingRequestFlyOrbit::Function4f7530()
{
 if (!registeredType) {
  RegisterType(&registeredType, typeName, nullptr);
 }
 return registeredType;
}
