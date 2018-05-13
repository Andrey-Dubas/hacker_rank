#include <vector>
#include <iostream>
#include <string>


class Graph
{
    private:
        std::vector<std::vector<int> > m_connections;
    public:
        Graph(int size)
            : m_connections(size+1)
        {

        }

        void connect(int v1, int v2)
        {
            m_connections[v1].push_back(v2);
            m_connections[v2].push_back(v1);
        }

        const std::vector<int>& adjacents(int v) const
        {
            return m_connections[v];
        }

        size_t size() const
        {
            return m_connections.size();
        }

};

void dfs_impl(const Graph& graph, int vertex, std::vector<bool>& marked, int depth, int& odd_counter, int& even_counter)
{

    if (depth % 2 == 0) 
    {
        even_counter++;
    }
    else
    {
        odd_counter++;
    }


    for (int next: graph.adjacents(vertex))
    {
        if (!marked[next])
        {
            marked[next] = true;
            dfs_impl(graph, next, marked, depth+1, odd_counter, even_counter);
        }
    }
}

int dfs(const Graph& graph, int startVertex)
{
    std::vector<bool> marked(graph.size(), false);
    marked[startVertex] = true;

    int odd_counter = 0, even_counter = 0;
    dfs_impl(graph, startVertex, marked, 0, odd_counter, even_counter);
    return (odd_counter*(odd_counter-1) + even_counter*(even_counter-1))/2 ;
}

std::vector<int> split(char* buffer)
{
    std::vector<int> result;
    if (!*buffer) return result;
    char* prevWordBegin = buffer;

    while (*buffer)
    {
        if (*buffer == ' ')
        {
            *buffer = 0;
            result.push_back(std::stoi(prevWordBegin));
            prevWordBegin = buffer+1;
        }
        buffer++;
    }
    result.push_back(std::stoi(prevWordBegin));

    return result;
}




int main()
{
    std::cin.seekg(0, std::cin.end);
    int lastPos = std::cin.tellg();
    std::cin.seekg(0, std::cin.beg);

    char buffer[255];
    std::cin.getline(buffer, 255);
    int testcases_num = std::stoi(buffer);
    std::vector<int> v;

    std::cin.getline(buffer, 255);
    int vertice = std::stoi(buffer);

    while (testcases_num--)
    {

        if (vertice == -1) break;

        Graph graph(vertice);
        while (true)
        {
            // if (std::cin.tellg() == lastPos)
            // {
            //     vertice = -1;
            //     break;
            // }
            std::cin.getline(buffer, 255);
            v = split(buffer);

            if (v.size() == 1)
            {
                vertice = v[0];
                break;
            }
            if (v.size() == 0)
            {
                break;
            }

            graph.connect(v[0], v[1]);
        }
        int counter = dfs(graph, 1);

        std::cout << counter << std::endl;
        if (v.size() == 0) break;
    }
}



