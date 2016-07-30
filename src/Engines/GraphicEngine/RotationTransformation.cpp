#include "Engines/GraphicEngine/RotationTransformation.hpp"

/* TODO : REWORK Transformation
GraphicMonsters::RotationTransformation::RotationTransformation()
{
	m_finalAngle = 0;
	m_angleDegreeAdvancement = 0;
	m_speedPerSecond = 0;
}

GraphicMonsters::RotationTransformation::~RotationTransformation()
{
	//void
}

void GraphicMonsters::RotationTransformation::initAttribute(GraphicMonsters::QuadVertices* m_quadVertices)
{
	Transformation::initAttribute(m_quadVertices);
}


void GraphicMonsters::RotationTransformation::initRotateByTime(float newSpeedPerSecond, double timeUntilTheEnd)
{
	m_finalAngle = (float)(m_speedPerSecond * timeUntilTheEnd);
	m_speedPerSecond = newSpeedPerSecond;
}

void GraphicMonsters::RotationTransformation::initRotateByAngle(float newSpeedPerSecond, float newFinalAngle)
{
	if (newFinalAngle < 0)
	{
		int endRotation = -(int)newFinalAngle % 360;
		float floatPart = newFinalAngle - (int)newFinalAngle;
		int nbOfTurn = (int)(newFinalAngle / -360);
		newFinalAngle = nbOfTurn * 360 + endRotation + floatPart;
	}
	m_finalAngle = newFinalAngle;
	m_angleDegreeAdvancement = 0;
	m_speedPerSecond = newSpeedPerSecond;
}

bool GraphicMonsters::RotationTransformation::actualize(double timeSpent, Vector2f const& origin
	, sf::Transform & transformationPoint)
{
	if (m_isOn)
	{
		bool isFinish = false;
		float angleRotation = m_speedPerSecond * (float)timeSpent;

		m_angleDegreeAdvancement += angleRotation;
		if (m_speedPerSecond > 0 && m_angleDegreeAdvancement >= m_finalAngle)
		{
			isFinish = calculateEndOfRotation(angleRotation, true);
		}
		else if (m_speedPerSecond < 0 && m_angleDegreeAdvancement <= -m_finalAngle)
		{
			isFinish = calculateEndOfRotation(angleRotation, false);
		}

		m_quadVertices->rotate(angleRotation, origin, transformationPoint);
		m_quadVertices->applyTranformation(transformationPoint);

		return isFinish;
	}
	return false;
}

bool GraphicMonsters::RotationTransformation::calculateEndOfRotation(float & angleRotation, bool speedUpperThanZero)
{
	if (m_isInfinite)
	{
		if (speedUpperThanZero)
		{
			m_angleDegreeAdvancement -= m_finalAngle;
			m_angleDegreeAdvancement = 0;
		}
		else
		{
			m_angleDegreeAdvancement += m_finalAngle;
			m_angleDegreeAdvancement;
		}
		return false;
	}

	if (speedUpperThanZero)
	{
		angleRotation -= m_angleDegreeAdvancement - m_finalAngle;
	}
	else
	{
		angleRotation -= m_finalAngle - m_angleDegreeAdvancement;
	}
	m_isOn = false;

	return true;
}
 */