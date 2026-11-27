// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x575800 std::shared_ptr<>::~shared_ptr<>
// 0x58eec0 std::shared_ptr<>::operator_
// 0x126f510 std::shared_ptr<>::operator_
// CI hash: 0x575800 ??1?$shared_ptr@UP12@@@std@@QEAA@XZ
// CI hash: 0x58eec0 ??4?$shared_ptr@UP12@@@std@@QEAAAEAV01@$$QEAV01@@Z
// CI hash: 0x126f510 ??4?$shared_ptr@UP12@@@std@@QEAAAEAV01@AEBV01@@Z
#include "Std_sptr_P12_575800.h"

template class std::shared_ptr<P12>;
template std::shared_ptr<P12> std::make_shared<P12>();
