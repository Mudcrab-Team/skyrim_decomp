// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingStreamMasterFile.cpp:5
// MasterFilePathingStreamWriteToBuffer, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x4e4130 MasterFilePathingStreamWriteToBuffer::GetClassType
#include "MasterFilePathingStreamWriteToBuffer.h"
unsigned int MasterFilePathingStreamWriteToBuffer::GetClassType()
{
    static unsigned int icrc;
    if (!icrc)
        BSCRC32::GenerateCRC(icrc, "MasterFilePathingStreamWriteToBuffer", 0);
    return icrc;

}
