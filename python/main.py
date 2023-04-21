import sys
from camera import Camera
import numpy as np
from hittable_list import HittableList
from sphere import Sphere
from utils import *
from hittable import HitRecord, Hittable, Lambertian, Metal
from ray import Ray
# from joblib import Parallel, delayed


def unit_vector(a: np.ndarray):
    return a / np.linalg.norm(a)


def write_to_ppm(data: str, filename: str, mode: str):
    with open(filename, mode) as f:
        f.write(data)


def color(r: Ray, world: Hittable, depth: int):
    rec = HitRecord(0.0, np.ndarray([]), np.ndarray([]), None)
    if world.hit(r, 0.001, sys.float_info.max, rec):
        scattered = Ray(np.array([]), np.array([]))
        target = rec.p + rec.normal + random_in_unit_sphere()
        scatter, attenuation = rec.material.scatter(r, rec, scattered)
        if (depth < 50 and scatter):
            return attenuation*(color(Ray(rec.p, target-rec.p), world, depth + 1))
        else:
            return np.array([0.0, 0.0, 0.0])
    else:
        unit_direction = unit_vector(r.direction)
        t = 0.5 * (unit_direction[1] + 1.0)
        return ((1.0 - t) * np.array([1.0, 1.0, 1.0]) + t*np.array([0.5, 0.7, 1.0]))


def render():
    rows = 200
    cols = 100
    ns = 100
    write_to_ppm(f"P3\n{rows} {cols}\n255\n", "canvas.ppm", "w")
    cam = Camera()
    world = HittableList([Sphere(np.array([0.0, 0.0, -1.0]), 0.5,
                                 Lambertian(np.array([0.8, 0.3, 0.3]))),
                          Sphere(np.array([0.0, -100.5, -1.0]), 100,
                                 Lambertian(np.array([0.8, 0.8, 0.0]))),
                          Sphere(np.array([1.0, 0.0, -1.0]), 0.5,
                                 Metal(np.array([0.8, 0.6, 0.2]))),

                          Sphere(np.array([-1.0, 0.0, -1.0]), 0.5,
                                 Metal(np.array([0.8, 0.8, 0.8])))
                          ])
    for y in range(cols, 0, -1):
        for x in range(rows):
            col = np.array([0.0, 0.0, 0.0])
            for i in range(ns):
                u = float(x) / float(rows)
                v = float(y) / float(cols)
                r = cam.get_ray(u, v)
                col += color(r, world, 0)

            col /= float(ns)
            col = col ** 0.5
            ir = int(255.99 * col[0])
            ig = int(255.99 * col[1])
            ib = int(255.99 * col[2])
            write_to_ppm(f"{ir} {ig} {ib}\n", "canvas.ppm", 'a')


render()
