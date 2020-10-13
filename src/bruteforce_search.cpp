#include "../headers/bruteforce_search.h"
#include <algorithm>

Brureforce_Search::Brureforce_Search(std::vector<Image*> images) {
    this->images = images;
}


std::vector<std::pair<double,int>> Brureforce_Search::exactNN(Image *q, int N) {
    // Calculate distance of q to all the points in the dataset
    std::vector<std::pair<double,int>> neighbors;
    
    for (unsigned i = 0; i < this->images.size(); i++) {
        std::pair<double,int> temp(q->distance(this->images[i], 1), this->images[i]->getId());
        neighbors.push_back(temp);
    }
    
    std::sort(neighbors.begin(), neighbors.end());
    neighbors.resize(N);
    return neighbors;
}

Brureforce_Search::~Brureforce_Search() {

}
