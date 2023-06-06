#ifndef MAGICAL_CONTAINER
#define MAGICAL_CONTAINER

#include <cstddef>
#include <stdexcept>
#include <iterator>
#include <set>
#include <list>
#include <vector>

using namespace std;


namespace ariel {

    class MagicalContainer {

        vector<int> originalContainer;     //stores original insertion order
        vector<int> ascendingContainer;    //stores in ascending order
        vector<int> sideCrossContainer;    //stores in cross order
        vector<int> primeContainer;        //stores prime numbers in original order    

    public:
        MagicalContainer() = default;
        ~MagicalContainer() = default;
        
        void addElement(int elem);
        void removeElement(int elem);
        static bool isPrime(int elem);
        int size();

        // template <typename T, typename U>
        // friend bool operator<(const T& leftIterator, const U& rightIterator){
        //     throw std::logic_error("cannot compare two different types");
        // }

        // template <typename T, typename U>
        // friend bool operator>(const T& leftIterator, const U& rightIterator){
        //     throw std::logic_error("cannot compare two different types");
        // }

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };


    class MagicalContainer::AscendingIterator {

    public:
        AscendingIterator(const MagicalContainer& magicalContainer);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator() = default;
        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();
        AscendingIterator& begin();
        AscendingIterator& end();
    };


    class MagicalContainer::SideCrossIterator {

    public:
        SideCrossIterator(const MagicalContainer& magicalContainer);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();
        SideCrossIterator& begin();
        SideCrossIterator& end();
    };


    class MagicalContainer::PrimeIterator {

    public:
        PrimeIterator(const MagicalContainer& magicalContainer);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();
        PrimeIterator& begin();
        PrimeIterator& end();
    };

}


#endif //MAGICAL_CONTAINER
