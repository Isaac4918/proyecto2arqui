"""
Initial Date: September 10th, 2022
Last Modification: September 28th, 2022
"""

#Loading the required modules
from scipy.spatial.distance import cdist 
import pandas as pd 
import numpy as np
import time


#Defining our function 
def kMeans(x, k, iterations):
    global assignments
    global comparisons
    global executedLines
   
    idx = np.random.choice(x.shape[0], k, replace=False)

    #Randomly choosing Centroids 
    centroids = x.iloc[idx, :] #Step 1
     
    #Finding the distance between centroids and all the data points
    distances = cdist(x, centroids ,'euclidean') #Step 2
     
    #Centroid with the minimum Distance
    points = np.array([np.argmin(i) for i in distances]) #Step 3

    #Repeating the above steps for a defined number of iterations
    for _ in range(iterations): #Step 4
        centroids = []
        for idx in range(k):
            #Updating Centroids by taking mean of Cluster it belongs to
            tempCent = x[points==idx].mean(axis=0) 
            centroids.append(tempCent)
 
        centroids = np.vstack(centroids) #Updated Centroids 
         
        distances = cdist(x, centroids ,'euclidean')

        points = np.array([np.argmin(i) for i in distances])
        
         
    return points 

def main():
    #Load data
    n = 100
    df = pd.DataFrame(np.random.randint(0,100,size=(100000, 3)), columns=list('ABC'))

    #Execution
    start = time.time()
    results = kMeans(df,3,n) #N iterations
    end = time.time()
 
    print("Execution Time", (end - start))
    #print(results)

main()