// Adds a road between two locations
    void addRoad(int u, int v, int distance)
    {
        cost[u][v] = distance; // Road from u to v
        cost[v][u] = distance; // Road from v to u
    }

    // Finds the shortest path using Dijkstra's algorithm
    void shortestPath(int source, int destination)
    {
        int dist[MAX];       // Shortest known distance from source
        int visited[MAX];    // Marks locations already processed
        int parent[MAX];     // Stores previous location in the path

        // Initialize all locations
        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;     // Initially, distance is unknown
            visited[i] = 0;    // No location is visited
            parent[i] = -1;    // No previous location
        }

        dist[source] = 0;      // Distance from source to itself is zero

        // Process each location
        for (int count = 0; count < n; count++)
        {
            int u = -1;
            int minDist = INF;

            // Find the unvisited location with minimum distance
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            // Stop if no reachable location remains
            if (u == -1)
                break;

            visited[u] = 1; // Mark the selected location as visited

            // Check all roads from the selected location
            for (int v = 0; v < n; v++)
            {
                // Update distance if a shorter route is found
                if (!visited[v] && cost[u][v] != INF &&
                    dist[u] + cost[u][v] < dist[v])
                {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u; // Store the previous location
                }
            }
        }

        // Check whether the destination can be reached
        if (dist[destination] == INF)
        {
            cout << "No path exists.\n";
            return;
        }

        int path[MAX]; // Stores the shortest path in reverse order
        int length = 0;
        int current = destination;

        // Trace the path backwards using the parent array
        while (current != -1)
        {
            path[length++] = current;
            current = parent[current];
        }
