# Extended Kalman Filter

I am being provided simulated Lidar and Radar measurements detecting a bicycle that travels around your vehicle. I will use a Kalman filter, Lidar measurements and Radar measurements to track the bicycle's position and velocity.

# Files contained

* `scr` : Contains the main code from the project.
** `main.cpp` : communicates with the Simulator receiving data measurements, calls a function to run the Kalman filter, calls a function to calculate RMSE.
** `FusionEKF.cpp` : Initializes the filter, calls the predict function, calls the update function.
** `kalman_filter.cpp` : Defines the predict function, the update function for lidar, and the update function for radar.
** `tools.cpp` : Function to calculate RMSE and the Jacobian matrix.






