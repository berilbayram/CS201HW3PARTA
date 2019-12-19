#include <iostream>
#include "SimpleBookCollection.h"
using namespace std;

void callDisplay(BookCollection collection){
    collection.displayGenres();
}

int main() {
    BookCollection collection = BookCollection();
    collection.setName("test");
    collection.addGenre("Rock");
    collection.addGenre("Metal");
    collection.removeGenre("Metal");
    collection.addGenre("rock");
    collection.addGenre("Pop");
    collection.removeGenre("Pop");
    BookCollection collection1 = BookCollection();
    collection1 = collection;
    collection1.addGenre("Beril");
    cout << "ch1" << endl;
    collection.displayGenres();
    cout << "ch2" << endl;
    collection1.displayGenres();
    collection1.removeGenre("Beril");
    cout << "ch3" << endl;
    callDisplay(collection1);
}