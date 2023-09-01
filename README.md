# SignaloidBernoulliLift
This is a simple example (test) of the usage of the Signaloid platform for uncertainty quantification (UQ). We will compute the lift generated on an airfoil based on the Bernoulli equation and introduce uncertainties of different types.

The Bernoulli equation states that, for a fluid in movement,  the following quantity

    	      P + ρ*g*h + 0.5*ρ*v^2,

remains constant (conservation of energy), where P is the pressure of the fluid (in Pascal), ρ is the density of the fluid (Kg/m^3), g is the gravitational acceleration (m/s^2), h is its height (m) and v its speed (m/s).

We will use the previous equation to compute the lift generated on an airfoil where, due to the shape of the airfoil, the speed of the air differs between the air above the wing and below the wing, generating a difference in pressure and, therefore, lift (a quick google search revealed this model to be highly questionable, and probably not a correct explanation of the phenomenon of lift, but since we are interested mostly on the tracking of uncertainty throughout the mathematical model, we will ignore this discussion).

A first source of uncertanty will be given by the density of the air, which will depend on the current temperature and absolute pressure, and may be computed from the ideal gas equation:

P*V = n*R*T,

where, P is the atmospheric pressure, V is the volume occupied with the gas, n is the number atoms of the gas (in moles), T is the temperature of the gas (in Kelvin) and R is the ideal gas constant 8.31446261815324 (in Pa*m^3/K*mol). Manipulating this equation, we get the following formula for the gas' density,

ρ = M*P/R*T,

where M is the molar mass of the gas (Kg/mol). We have assumed that the temperature is to be modelled through a normal distribution (perhaps fitted through data) with a mean of 293 K (20 celsius) and a standard deviation of 5 degrees, while the pressure is assumed to come from 5 different samples, whereupon we allow the tool to get its distribution. The air density is then computed throigh the formula above.

With the air density at hand, we continue calculating the lift. We assume the difference in height from the air below and above the airfoil to be negligible, so that it holds that

P_a + 0.5*ρ*v_a^2 = P_b + 0.5*ρ*v_b^2,

where the subindices a and b reflect the situation above and below the airfoil, respectively. From the pressure above and below the airfoil we may compute the forces acting on it, since we have that

P = F/A,

where F is force (in Newton) and A is the area (in m^2) acting on the airfoil. We further assume the area above and below the airfoil to be equal, so that we may compute lift (the difference of the forces acting above and below the airfoil) as

Lift = 0.5*ρ*(v_a^2 - v_b^2)*A.

For simplicity, we have assumed the area of the airfoil to be equal to that of the wings of a Cessna plane (16.17 m^2, obtained through a quick google search) and deterministic. The velocity of the airfoil/plane is taken as a uniform variable centered at the maximum speed of the same plane (84 m/s). The velocity above and below the plane are then assumed to have a fixed difference from that of the plane.

