#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int elem) {
    cout <<  elem << endl;
}

void MagicalContainer::removeElement(int elem) {
    cout  << elem << endl;
}

bool MagicalContainer::isPrime(int elem) {
    if (elem <= 1) {
        return false;
    }
    for (int i = 2; i < elem / 2; i++) {
        if (elem % i == 0) {
            return false;
        }
    }
    return true;
}

int MagicalContainer::size() {
    return this->originalContainer.size();
}

//-----------------Ascending iterator------------------------
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& magicalContainer) {
    cout << "constructor" << endl;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) {
    cout << "copy constructor" << endl;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return false;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return 0;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    return *this;
}

//-----------------SideCross iterator------------------------
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& magicalContainer) {
    cout << "constructor" << endl;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) {
    cout << "copy constructor" << endl;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return 0;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    return *this;
}

//-----------------Prime iterator------------------------
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& magicalContainer) {
    cout << "constructor" << endl;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) {
    cout << "copy constructor" << endl;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return false;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return 0;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    return *this;
}


