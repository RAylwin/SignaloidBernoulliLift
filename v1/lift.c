elvin] = %lf\n", temperature);
printf("Pressure[Pascal] = %lf\n", pressure);

    // Then, the air density is given by the following formula (derived from ideal gas formula)
    double airDensity = pressure*molWeightAir/(R*temperature);
    printf("Air density[Kg/m^3] = %lf\n", airDensity);

    // For our simple model, based on Bernoulli's equations, we also require the wind's
    // velocity both above and below the wing. We will get them from the velocity of
    // the plane, for which we also assume measurement uncertainty
    double planeVelocity; // The velocity of the plane
    loadUniformMeanPert(&planeVelocity, 84, 0.005); //[m/s], maximum speed of Cessna 172

// For this simple model, we assume the velocity above and below the plane to be
// given by a fixed difference from the plane velocity
double velocityAbove = planeVelocity + 10;
double velocityBelow = planeVelocity - 5;
// The only strong restriction to our model is that velocityAbove > velocityBelow

// We also need the wing Area on both its faces, above and below. We Assume a plane for which
// the areas of its wing's faces are equal. For simplicity, we take it certain.
double wingArea = 16.17; // [m^2], area of a cessna's wings

// Then, the lift force will be given by the following formula
double force = 0.5*airDensity*(velocityAbove*velocityAbove - velocityBelow*velocityBelow)*wingArea; // [N]

printf("Lift force[N] = %lf\n", force);


return 0;
}

void loadUniformMinMax(double * data, double min, double max)
{
  *data = UxHwDoubleUniformDist(min, max);
  return;
}

void loadUniformMeanPert(double * data, double mean, double perturbation)
{
  double min = mean * (1.0 - perturbation);
  double max = mean * (1.0 + perturbation);
  loadUniformMinMax(data, min, max);
  return;
}

void loadGauss(double * data, double mean, double stdDev)
{
  *data = UxHwDoubleGaussDist(mean, stdDev);
  return;
}
