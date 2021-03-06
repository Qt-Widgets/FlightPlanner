#ifndef COVERAGETASK_H
#define COVERAGETASK_H

#include <QObject>
#include <QVector>
#include <QVector3D>

#include "FlightTask.h"

class CoverageTask : public FlightTask
{
    Q_OBJECT
public:
    CoverageTask(qreal coverageGranularity = 100.0, qreal maxSatisfyingDistance = 50.0);

    //for de-serializing
    CoverageTask(QDataStream& stream);

    //pure-virtual from Serializable
    virtual QString serializationType() const;

    //pure-virtual from Serializable
    virtual void serialize(QDataStream& stream) const;

    virtual QString taskType() const;

    virtual qreal calculateFlightPerformance(const QList<Position>& positions,
                                             const QPolygonF& geoPoly,
                                             const UAVParameters& uavParams);

    virtual qreal maxTaskPerformance() const;

    qreal granularity() const;
    void setGranularity(qreal nGran);

    qreal maxDistance() const;
    void setMaxDistance(qreal maxDist);
    
//private:
    void _calculateBins(const QPolygonF& geoPoly);

    QPolygonF _lastGeoPoly;
    QVector<Position> _bins;
    QVector<QVector3D> _xyzBins;

    qreal _granularity;
    qreal _maxDistance;
    
};

#endif // COVERAGETASK_H
