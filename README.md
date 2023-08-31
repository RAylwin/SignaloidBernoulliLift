# SignaloidBernoulliLift
This is a simple example (test) of the usage of the Signaloid platform for uncertainty quantification (UQ). We will compute the lift generated on an airfoil based on the Bernoulli equation and introduce uncertainties of different types.

The Bernoulli equation states that, for a fluid in movement,  the following quantity

    	      P + ρ*g*h + 0.5*ρ*v^2,

remains constant (conservation of energy), where P is the pressure of the fluid (in Pascal), ρ is the density of the fluid (Kg/m^3), g is the gravitational acceleration (m/s^2), h is its height (m) and v its speed (m/s).

We will use the previous equation to compute the lift generated on an airfoil where, due to the shape of the airfoil, the speed of the air differs between the air above the wing and below the wing, generating a difference in pressure and, therefore, lift (a quick google search revealed this model to be highly questionable, and probably not a correct explanation of the phenomenon of lift, but since we are interested mostly on the tracking of uncertainty throughout the mathematical model, we will ignore this discussion).
