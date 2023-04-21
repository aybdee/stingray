import numpy


class Ray:
    def __init__(self, origin: numpy.ndarray, direction: numpy.ndarray):
        self.origin = origin
        self.direction = direction

    def __repr__(self):
        return f"origin: {self.origin}\n direction:{self.direction}"

    def point_at_parameter(self, t: float):
        return self.origin + (t * self.direction)
