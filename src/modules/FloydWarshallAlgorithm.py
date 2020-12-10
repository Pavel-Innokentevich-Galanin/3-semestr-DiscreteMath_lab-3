def FloydWarshallAlgorithm(arr):
    for k in range(len(arr)):
        for i in range(len(arr)):
            for j in range(len(arr[i])):
                #arr[i][j] = arr[i][j] or arr[i][k] and arr[k][j] # not work
                arr[i][j] = min( arr[i][j], arr[i][k] + arr[k][j] )
    return arr
          