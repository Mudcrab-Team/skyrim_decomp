// Source exposure: binary-analysis.
// Code origin: original reconstruction of the straight-line request copy.
// 0x4f9360 PathingRequestSafeStraightLine::CopyMembers
#include "PathingRequestSafeStraightLine_4f9360.h"

void PathingRequestSafeStraightLine::CopyMembers(PathingRequestSafeStraightLine& destination) const
{
    PathingRequest::CopyMembers(destination);
    destination.straightLineState = straightLineState;
}
