import numpy as np
from random import rand


def unit_vector(a: np.ndarray):
    return a / np.linalg.norm(a)


def random_in_unit_sphere():
    p = 2.0 * np.array([random(), random(), random()]) - \
        np.array([1.0, 1.0, 1.0])
    while ((np.linalg.norm(p) ** 2) >= 1.0):
        p = 2.0 * np.array([random(), random(), random()]) - \
            np.array([1.0, 1.0, 1.0])
    return p
