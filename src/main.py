import numpy
import math

from modules.FloydWarshallAlgorithm import FloydWarshallAlgorithm

if __name__ == '__main__':
    oo = math.inf

    graph = numpy.array(
        [
            [oo, 10, oo, 8,  oo, oo, oo],
            [oo, oo, 7,  oo, oo, oo, oo],
            [oo, oo, oo, 11, 5,  6,  oo],
            [oo, oo, oo, oo, 8,  oo, oo],
            [oo, oo, oo, oo, oo, 4,  oo],
            [oo, oo, oo, oo, oo, oo, 9 ],
            [oo, oo, oo, oo, oo, oo, oo]
        ]
    )   

    a = FloydWarshallAlgorithm(graph)
    print(a)
