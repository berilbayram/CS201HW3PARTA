//
// Created by berilbayram on 7.12.2019.
//

#include "SimpleGenre.h"
using namespace std;

Genre::Genre(const string gname) {
    genreName = gname;
}

Genre::~Genre(){
}

string Genre::getGenreName() const {
    return genreName;
}

void Genre::setGenreName(const std::string gName) {
    genreName = gName;
}

Genre::Genre (const Genre &genreToCopy) {
    genreName = genreToCopy.getGenreName();
}

void Genre::operator=(const class Genre & right) {
    genreName = right.getGenreName();
}