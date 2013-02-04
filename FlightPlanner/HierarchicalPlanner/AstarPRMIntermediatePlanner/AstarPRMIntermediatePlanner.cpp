#include "AstarPRMIntermediatePlanner.h"

AstarPRMIntermediatePlanner::AstarPRMIntermediatePlanner(const Position &startPos,
                                                         const UAVOrientation &startPose,
                                                         const Position &endPos,
                                                         const UAVOrientation &endPose,
                                                         const QList<QPolygonF> &obstacles) :
    IntermediatePlanner(startPos, startPose, endPos, endPose, obstacles)
{
}

bool AstarPRMIntermediatePlanner::plan()
{
    _results.clear();

    //build graph



    return true;
}

QList<Position> AstarPRMIntermediatePlanner::results() const
{
    return _results;
}