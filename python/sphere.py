from math import sqrt
from sympy import discriminant
from ray import Ray
import numpy as np
from hittable import HitRecord, Hittable, Metal, Material
from random import random


class Sphere(Hittable):
    def __init__(self, cen: np.ndarray, r: float, material: Material):
        self.centre = cen
        self.radius = r
        self.material = material

    def hit(self, r: Ray, t_min: float, t_max: float, rec: HitRecord):
        oc = r.origin - self.centre
        a = np.dot(r.direction, r.direction)
        b = np.dot(oc, r.direction)
        c = np.dot(oc, oc) - (self.radius * self.radius)
        discriminant = (b*b) - (a*c)
        if discriminant > 0:
            temp = (-b - sqrt(b*b - a*c)) / a
            if temp < t_max and temp > t_min:
                rec.t = temp
                rec.p = r.point_at_parameter(rec.t)
                rec.normal = (rec.p - self.centre) / self.radius
                rec.material = self.material
                return True
            temp = (-b + sqrt(b*b - a*c)) / a
            if temp < t_max and temp > t_min:
                rec.t = temp
                rec.p = r.point_at_parameter(rec.t)
                rec.normal = (rec.p - self.centre) / self.radius
                return True
        return False
