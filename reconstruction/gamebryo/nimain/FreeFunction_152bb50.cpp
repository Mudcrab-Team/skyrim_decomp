// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// 0x152bb50 SubmitCullResultsJob
#include "FreeFunction_152bb50.h"

class AutoMemContext
{
public:
    explicit AutoMemContext(std::uint32_t context) : previous(memoryContext)
    {
        memoryContext = context;
    }

    ~AutoMemContext()
    {
        memoryContext = previous;
    }

private:
    std::uint32_t previous;
};

void SubmitCullResultsJob(CullDescriptor* descriptor)
{
    AutoMemContext context(32);
    descriptor->geometryListProcess->SubmitCullResults(
        descriptor->lightData, descriptor->camera, descriptor->unk61, false);
}
