def k_means_clustering(points: list[tuple[float, float]], k: int, initial_centroids: list[tuple[float, float]], max_iterations: int) -> list[tuple[float, float]]:


    centroids = list(initial_centroids)
    for _ in range(max_iterations):
        clusters = [[] for _ in range(k)]

        for point in points:
            px,py = point
            min_dist = float('inf')
            index = 0

            for i in range(k):
                cx,cy = centroids[i]

                dist = (px-cx)*(px-cx) + (py-cy)*(py-cy)

                if(dist < min_dist):
                    min_dist = dist
                    index = i

            clusters[index].append(point)
        

        new_centroid = []
        for i in range(k):
            if len(clusters[i]) == 0:
                new_centroid.append(initial_centroids[i])
                continue
            x_sum = 0
            y_sum = 0
            for x,y in clusters[i]:
                x_sum += x
                y_sum += y

            x_avg = x_sum / len(clusters[i])
            y_avg = y_sum / len(clusters[i])
            new_centroid.append((x_avg,y_avg))

        centroids = new_centroid


	# Your code here
	return centroids
