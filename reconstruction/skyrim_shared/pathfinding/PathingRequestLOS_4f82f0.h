// p202_8af09832: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// p202_8af09832: GUESS(low)
// PathingRequestLOS, Function4f82f0, registeredType, typeName, RegisterType: GUESS(low)
// PathingRequestLOS: STANDIN GUESS(low)
#pragma once
#include <cstdint>
namespace p202_8af09832 {
extern std::uint32_t registeredType;
extern const char typeName[];
void RegisterType(std::uint32_t*, const char*, void*);
}
class PathingRequestLOS {
public:
 std::uint32_t Function4f82f0();
};
