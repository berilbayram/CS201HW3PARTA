//
// Created by berilbayram on 7.12.2019.
//

#include "SimpleBookCollection.h"
#include <iostream>
#include <string>
using namespace std;


BookCollection::BookCollection(){
    genreCount = 0;
    head = nullptr;
    name = "";
}

BookCollection::~BookCollection(){
   for(int i = genreCount; i != 0; i--){
       removeGenre(head->g.getGenreName());
   }
   genreCount = 0;
}

BookCollection:: BookCollection( const BookCollection &bcToCopy){
    genreCount = bcToCopy.genreCount;
    if (bcToCopy.head == nullptr){
        head = nullptr;
    } else {
        head = new GenreNode;
        head->g = bcToCopy.head->g;
        GenreNode* newPtr = head;

        for(GenreNode* bcToCopyGenrePtr = bcToCopy.head->next; bcToCopyGenrePtr != nullptr; bcToCopyGenrePtr = bcToCopyGenrePtr->next){
            newPtr->next = new GenreNode;
            newPtr = newPtr->next;
            newPtr->g = bcToCopyGenrePtr->g;
        }
        newPtr->next = nullptr;
    }
}

string BookCollection::getName() const {
    return name;
}

void BookCollection::setName(const std::string bcName) {
    name = bcName;
}

string toUpper(string str) {
    string upper = "";
    for( int i = 0; i < str.length(); ++i)
        upper += toupper(str[i]);
    return upper;
}

BookCollection::GenreNode* BookCollection::findGenre(string genreName) {
    for(GenreNode* current = head; current != nullptr; current = current->next){
        if (current->g.getGenreName() == genreName || toUpper(current->g.getGenreName()) == toUpper(genreName)){
            return current;
        }
    }
    return nullptr;
}

bool BookCollection::addGenre(const std::string genreName) {
    GenreNode* temp;
    temp = findGenre(genreName);
    if (temp == nullptr){
        temp = new GenreNode;
        temp->g.setGenreName(genreName);
        temp->next = head;
        head = temp;
        genreCount++;
        return true;
    }
    cout << "ERROR: This genre("<< genreName <<") exists!" << endl;
    return false;
}

bool BookCollection::removeGenre(const std::string genreName) {
    GenreNode* temp = findGenre(genreName);
    int index = 0;
    if(temp != nullptr) {
        if (temp == head) {
            temp = head;
            head = head->next;
            genreCount--;
        } else {
            for (GenreNode *current = head; current != nullptr; current = current->next) {
                if (current->g.getGenreName() == genreName) {
                    return index;
                }
                index++;
            }
            index = index - 1;
            GenreNode *previousNode = head;
            while (index > 0) {
                previousNode = previousNode->next;
                index--;
            }
            temp = previousNode->next;
            previousNode->next = temp->next;
            genreCount--;
        }
        temp->next = nullptr;
        delete temp;
        return true;
    }
    cout << "This genre does not exist!" << endl;
    return false;
}

void BookCollection::displayGenres() const {
    if (head == nullptr){
        cout<<"--EMPTY--"<<endl;
    } else{
        for(GenreNode* current = head; current != nullptr; current = current->next){
            if(current->g.getGenreName() == ""){
                cout<<"--EMPTY--"<< endl;
            } else{
                cout<< "Genre: " << current->g.getGenreName()<<endl;
            }
        }
    }
}
