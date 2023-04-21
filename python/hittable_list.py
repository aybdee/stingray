from hittable import Hittable, HitRecord
import numpy as np
from ray import Ray
from typing import List


class HittableList(Hittable):
    def __init__(self, objects: List[Hittable]):
        self.objects = objects

    def hit(self, r: Ray, t_min: float, t_max: float, rec: HitRecord):
        temp_rec = HitRecord(0.0, np.ndarray([]), np.ndarray([]))
        hit_anything = False
        closest_so_far = t_max
        for object in self.objects:
            if object.hit(r, t_min, closest_so_far, temp_rec):
                hit_anything = True
                closest_so_far = temp_rec.t
                rec.t = temp_rec.t
                rec.p = temp_rec.p
                rec.normal = temp_rec.normal
        return hit_anything
