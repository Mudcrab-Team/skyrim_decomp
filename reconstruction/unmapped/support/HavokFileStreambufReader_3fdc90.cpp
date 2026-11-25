// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0056b360::HavokFileStreambufReader::~HavokFileStreambufReader.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:4729
// 0x3fdc90 f3m_0056b360::HavokFileStreambufReader::~HavokFileStreambufReader
#include "HavokFileStreambufReader_3fdc90.h"

namespace f3m_0056b360 {
HavokFileStreambufReader::~HavokFileStreambufReader()
{
    if (m_pObject != 0 && m_bOwnObject)
        delete m_pObject;
}
}
