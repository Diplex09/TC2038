'''
/*                                                  */
/*  Actividad Integradora 2 - Servicios de internet */
/*                                                  */
/*  Diego Velazquez Moreno - A01632240              */
/*  Aldo Alejandro Degollado Padilla - A01638391    */
/*                                                  */
'''

import numpy as np
from shapely.geometry import Polygon
from scipy.spatial import Voronoi

def voronoi_limits(limits, cords_points, max_value):
    temporal_points = np.concatenate([cords_points, np.array([[100, 100], [100, -100], [-100, 0]])])
    voronoi = Voronoi(temporal_points)
    polygon_limits = Polygon(limits)
    
    voronoi_polygon = []
    
    for i in range(len(temporal_points) - 3):
        voronoi_polygon_limits = [voronoi.vertices[char] for char in voronoi.regions[voronoi.point_region[i]]]
        intersection_limits = polygon_limits.intersection(Polygon(voronoi_polygon_limits))
        voronoi_polygon.append(list(intersection_limits.exterior.coords[:-1]))
    
    points_list = []

    for i in range(len(voronoi_polygon)):

        polygon_points = []

        for j in range(len(voronoi_polygon)):
            temporal_points_list = list(voronoi_polygon[i][j])
            temporal_points_list[0] *= max_value
            temporal_points_list[1] *= max_value
            point = tuple(temporal_points_list)
            polygon_points.append(point)

        points_list.append(polygon_points)

    for i in range(len(points_list)):
        print(f'Polygon {i+1}\n', points_list[i], '\n')

def voronoi(cords):
    max_value = max([max(char) for char in cords])
    limits = np.array([[0, 0], [1, 0], [1, 1], [0, 1]])
    points = np.array(cords)
    points = np.true_divide(points, max_value)
    voronoi_polygon = voronoi_limits(limits, points, max_value)

lines = []

with open('Case1.txt') as file:

    for char in file:
        if '(' in char:
            lines.append(char)
    
    cords = []

    for char in lines:
        new_lines = char.replace("\n", "").replace("(", "").replace(")", "")
        cord_separation = new_lines.split(',')
        cord_x = cord_separation[0]
        cord_y = cord_separation[1]
        cords.append([float(cord_x), float(cord_y)])

    print("\n |-|-|-|-|-| Act Integradora 2 |-|-|-|-|-|")
    print("By: Aldo Degollado, Diego Velazquez\n")

    voronoi(cords)
