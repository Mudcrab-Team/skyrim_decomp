// Source exposure: binary-analysis.
// Code origin: original reconstruction of embedded list operations and request settings output.
// 0x11cbea0 PathingRequest::GetIndexList
// 0x11cbeb0 PathingRequest::ClearIndexList
// 0x11cbef0 PathingRequest::SetIndex
// 0x11cbfd0 PathingRequest::ReadSettings
#include "PathingRequest_11cbea0.h"

// requestDistanceThreshold: GUESS(low)
extern float requestDistanceThreshold;

PathRequestIndexList& PathingRequest::GetIndexList()
{
    return indexList;
}

void PathingRequest::ClearIndexList()
{
    indexList.Resize(0);
}

void PathingRequest::SetIndex(std::uint32_t index)
{
    indexList.Resize(3);
    indexList.SetOrAppend(index);
}

void PathingRequest::ReadSettings(PathRequestSettings& output) const
{
    output.exceedsThreshold = !(requestDistanceThreshold > requestDistance);
    output.option5 = (flags >> 5) & 1;
    output.option4 = (flags >> 4) & 1;
    output.requestID = requestID;
}
