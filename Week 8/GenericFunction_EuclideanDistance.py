from typing import List,TypeVar
import math

T=TypeVar('T',int,float)  # type variable for int or float

def euclidean_distance(point1:List[T], point2:List[T])->float:
    if len(point1)!=len(point2):
        raise ValueError("Points must have the same dimension")
    return math.sqrt(sum((x-y)**2 for x,y in zip(point1, point2)))

point_a=[1,2,3]
point_b=[4,5,6]
print("Euclidean distance (int points):",euclidean_distance(point_a,point_b))

point_c=[1.5,2.5,3.5]
point_d=[4.5,5.5,6.5]
print("Euclidean distance (float points):",euclidean_distance(point_c,point_d))