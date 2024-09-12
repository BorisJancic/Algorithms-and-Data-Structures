#ifndef __EDGE__
#define __EDGE__

class Edge {
    private:
        unsigned source;
        unsigned dest;
        unsigned weight;
    public:
        Edge(int source, int dest, int weight);
        ~Edge();
        void set_source(unsigned source);
        void set_dest(unsigned dest);
        void set_weight(unsigned weight);

        int get_source();
        int get_dest();
        int get_weight();
};

#endif