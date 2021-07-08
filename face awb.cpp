#include <stdio.h>
#include <math.h>
int main()
{
	double agw_rg = 0.744766, agw_bg = 0.465642;
	double light_gw_rg = 0.7822757, light_gw_bg = 0.4594172;
	double dark_gw_rg = 0.7697492, dark_gw_bg = 0.4784146;
	double lux = 200, cct = 4000;
	double light_distance, dark_distance, ratio;
	double weight11, weight22, weight33,weight;
	double weight1(double);
	double weight2(double,double);
	double weight3(double, double);
	light_distance = sqrt(pow((1 / agw_rg - 1 / light_gw_rg), 2) + pow((1 / agw_bg - 1 / light_gw_bg), 2));
	dark_distance = sqrt(pow((1 / agw_rg - 1 / dark_gw_rg), 2) + pow((1 / agw_bg - 1 / dark_gw_bg), 2));
	ratio = dark_distance / light_distance;
	weight11 = weight1(ratio);
	weight22 = weight2(lux, cct);
	weight33 = weight3(lux, cct);
	weight = weight11 * weight22 * weight33;
	printf("light_distance=%f,dark_distance=%f,ratio=%f,weight11=%f,weight22=%f,weight33=%f,weight=%f\n", light_distance,dark_distance, ratio, weight11, weight22, weight33, weight);
	return 0;
}
double weight1(double ratio)
{
	double weight;
	if ( ratio <= 0.3)
		weight = 0;
	else if (ratio >= 3.5)
		weight = 1;
	else
		weight = (ratio - 0.3) / (3.5-0.3);
	return weight;
}

double weight2(double lux, double cct)
{
	double weight, weight1, weight2;
	if (lux <= 159)
	{
		if (cct <= 2800)
			weight = 0.5;
		else if (cct >= 4500)
			weight = 0.95;
		else
			weight = (0.95 - 0.5) / (4500 - 2800)*(cct - 2800) + 0.5;

	}
	else if (lux >= 255)
	{
		if (cct <= 2800)
			weight = 0.95;
		else if (cct >= 4500)
			weight = 0.8;
		else
			weight = (0.8 - 0.95) / (4500 - 2800)*(cct - 2800) + 0.95;
	}
	else
	{
		if (cct <= 2800)
			weight1 = 0.5;
		else if (cct >= 4500)
			weight1 = 0.95;
		else
			weight1 = (0.95 - 0.5) / (4500 - 2800)*(cct - 2800) + 0.5;
		printf("weight2(weight1)=%f\n", weight1);

		if (cct <= 2800)
			weight2 = 0.95;
		else if (cct >= 4500)
			weight2 = 0.8;
		else
			weight2 = (0.8 - 0.95) / (4500 - 2800)*(cct - 2800) + 0.95;
		printf("weight2(weight2)=%f\n", weight2);

		weight = (weight2 - weight1) / (255 - 159)*(lux - 159) + weight1;

	}
	return weight;
		
}

double weight3(double lux, double cct)
{
	double weight, weight1, weight2;
	if (lux <= 159)
	{
		if (cct <= 2800)
			weight = 0.3;
		else if (cct >= 4500)
			weight = 0.95;
		else
			weight = (0.95 - 0.3) / (4500 - 2800)*(cct - 2800) + 0.3;

	}
	else if (lux >= 255)
	{
		if (cct <= 2800)
			weight = 0.95;
		else if (cct >= 4500)
			weight = 0.3;
		else
			weight = (0.3 - 0.95) / (4500 - 2800)*(cct - 2800) + 0.95;
	}
	else
	{
		if (cct <= 2800)
			weight1 = 0.3;
		else if (cct >= 4500)
			weight1 = 0.95;
		else
			weight1 = (0.95 - 0.3) / (4500 - 2800)*(cct - 2800) + 0.3;
		printf("weight3(weight1)=%f\n", weight1);

		if (cct <= 2800)
			weight2 = 0.95;
		else if (cct >= 4500)
			weight2 = 0.3;
		else
			weight2 = (0.3 - 0.95) / (4500 - 2800)*(cct - 2800) + 0.95;
		printf("weight3(weight2)=%f\n", weight2);

		weight = (weight2 - weight1) / (255 - 159)*(lux - 159) + weight1;

	}
	return weight;

}


