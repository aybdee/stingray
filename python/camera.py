import numpy as np
from ray import Ray


class Camera:

    def __init__(self):
        self.lower_left_corner = np.array([-2.0, -1.0, -1.0])
        self.horizontal = np.array([4.0, 0.0, 0.0])
        self.vertical = np.array([0.0, 2.0, 0.0])
        self.origin = np.array([0.0, 0.0, 0.0])

    def get_ray(self, u: float, v: float):
        r = Ray(self.origin, (self.lower_left_corner + u * self.horizontal +
                              v * self.vertical - self.origin))
        return r
