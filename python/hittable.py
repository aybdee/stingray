from ray import Ray
# from material import Material
import numpy as np
from utils import *


class HitRecord:
    def __init__(self, t: float, p: np.ndarray, normal: np.ndarray, material):
        self.t = t
        self.p = p
        self.normal = normal
        self.material = material


class Hittable:
    def hit(self, r: Ray, t_min: float, t_max: float, rec: HitRecord):
        pass


class Material:
    def scatter(self, r_in: Ray, hit_records: HitRecord,  scattered: Ray):
        pass


def reflect(v: np.ndarray, n: np.ndarray):
    return v - 2 * np.dot(v, n) * n


class Lambertian(Material):
    def __init__(self, albedo):
        self.albedo = albedo

    def scatter(self, r_in: Ray, rec: HitRecord, scattered: Ray):
        target = rec.p + rec.normal + random_in_unit_sphere()
        scattered = Ray(rec.p, target-rec.p)
        return True, self.albedo


class Metal(Material):
    def __init__(self, albedo, f: float):
        if f < 1:
            self.fuzz = f
        else:
            self.fuzz = 1
        self.albedo = albedo

    def scatter(self, r_in: Ray, rec: HitRecord, scattered: Ray):
        reflected = reflect(unit_vector(r_in.direction), rec.normal)
        scattered = Ray(rec.p, reflected + self.fuzz*random_in_unit_sphere())
        scattered.origin = rec.p
        scattered.direction = reflected
        return np.dot(scattered.direction, rec.normal) > 0, self.albedo
