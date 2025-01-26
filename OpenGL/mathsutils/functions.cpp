#include"functions.h"

float distance(float p1x,float p2x,float p1y,float p2y,float p1z,float p2z)
{
	float d = sqrt(((p1x - p2x) * (p1x - p2x)) + ((p1y - p2y) * (p1y - p2y)) + ((p1z - p2z) * (p1z - p2z)));
	return d;
}
