#include "doctest.h"

#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;
using namespace std;

TEST_CASE("Add and remove elements to MagicalContainer") {
    MagicalContainer container;

    SUBCASE("Add one element") {
        container.addElement(17);
        CHECK(container.size() == 1);
    }

    SUBCASE("Add elements") {
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        CHECK(container.size() == 5);
    }

    SUBCASE("Remove one element") {
        container.removeElement(17);
        CHECK(container.size() == 4);
    }

     SUBCASE("Remove elements") {
        container.removeElement(2);
        container.removeElement(25);
        container.removeElement(9);
        CHECK(container.size() == 1);
    }
}

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    MagicalContainer container2;
    MagicalContainer container3;

    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    container2.addElement(169);
    container2.addElement(89);
    container2.addElement(1);
    container2.addElement(11);
    container2.addElement(55);


    MagicalContainer::AscendingIterator ascendingIterator(container);
    MagicalContainer::AscendingIterator ascendingIterator2(ascendingIterator);    //copy constructor
    MagicalContainer::AscendingIterator ascendingIterator3(container2);

    
    SUBCASE("Check on an empty container") {
        MagicalContainer::AscendingIterator ascendingIterator4(container3);
        CHECK(ascendingIterator4 == ascendingIterator4.end());
    }                

    SUBCASE("Check comparison") {
        CHECK((ascendingIterator == ascendingIterator2));
        CHECK_THROWS_AS(ascendingIterator.operator==(ascendingIterator3), std::invalid_argument);
        CHECK_THROWS_AS(ascendingIterator.operator<(ascendingIterator3), std::invalid_argument);
        CHECK_THROWS_AS(ascendingIterator.operator>(ascendingIterator3), std::invalid_argument);
        CHECK_THROWS_AS(ascendingIterator.operator!=(ascendingIterator3), std::invalid_argument);
    }

    SUBCASE("++ check") {
    ++ascendingIterator;
    CHECK(*ascendingIterator == 3);
    CHECK((ascendingIterator != ascendingIterator2));
    }

    SUBCASE("Check the smallest element of the container") {
        CHECK(*ascendingIterator.begin() == 2);                           // check if the smallest element is 2 in "container"
        CHECK(*ascendingIterator.begin() == *ascendingIterator2.begin()); // will be the same value "2" (copy constructor)
        CHECK(*ascendingIterator3.begin() == 1);                          // check if the smallest element is 1 in "container2"
    }      

    SUBCASE("Check the biggest element of the container") {
        CHECK(*ascendingIterator.end() == 25);                           // check if the biggest element is 25 in "container"
        CHECK(*ascendingIterator.end() == *ascendingIterator2.end());    // will be the same value "25" (copy constructor)
        CHECK(*ascendingIterator3.end()== 169);                          // check if the biggest element is 169 in "container2"
    }   

    SUBCASE("Check order of ascendingIterator") {             
        int TrueOrder[] = {2,3,9,17,25};
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == TrueOrder[0]);
        ++it;
        CHECK(*it == TrueOrder[1]);
        ++it;
        CHECK(*it == TrueOrder[2]);
        ++it;
        CHECK(*it == TrueOrder[3]);
        ++it;
        CHECK(*it == TrueOrder[4]);
    }
}

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    MagicalContainer container2;
    MagicalContainer container3;

    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    container2.addElement(169);
    container2.addElement(89);
    container2.addElement(1);
    container2.addElement(11);
    container2.addElement(55);


    MagicalContainer::SideCrossIterator sideCrossIterator(container);
    MagicalContainer::SideCrossIterator sideCrossIterator2(sideCrossIterator); //copy constructor
    MagicalContainer::SideCrossIterator sideCrossIterator3(container2);

    
    SUBCASE("Check on an empty container") {
        MagicalContainer::SideCrossIterator sideCrossIterator4(container3);
        CHECK(sideCrossIterator4 == sideCrossIterator4.end());
    }                

    SUBCASE("++ check") {
    ++sideCrossIterator;
    CHECK(*sideCrossIterator == 3);
    CHECK((sideCrossIterator != sideCrossIterator2));
    }

    SUBCASE("Check the smallest element of the container") {
        CHECK(*sideCrossIterator.begin() == 2);                           // check if the smallest element is 2 in "container"
        CHECK(*sideCrossIterator.begin() == *sideCrossIterator2.begin()); // will be the same value "2" (copy constructor)
        CHECK(*sideCrossIterator3.begin() == 1);                           // check if the smallest element is 1 in "container2"
    }      

    SUBCASE("Check the biggest element of the container") {             
        CHECK(*sideCrossIterator.end() == 9);                           // check if the biggest element is 9 in "container"
        CHECK(*sideCrossIterator.end() == *sideCrossIterator2.end());   // will be the same value "9" (copy constructor)
        CHECK(*sideCrossIterator3.end()== 55);                          // check if the biggest element is 55 in "container2"
    }   

    SUBCASE("Check order of sideCrossIterator") {             
        int TrueOrder[] = {2,25,3,17,9};
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == TrueOrder[0]);
        ++it;
        CHECK(*it == TrueOrder[1]);
        ++it;
        CHECK(*it == TrueOrder[2]);
        ++it;
        CHECK(*it == TrueOrder[3]);
        ++it;
        CHECK(*it == TrueOrder[4]);
    }
}


TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    MagicalContainer container2;
    MagicalContainer container3;

    container.addElement(17);   //prime
    container.addElement(2);    //prime
    container.addElement(25);   //non-prime
    container.addElement(9);    //non-prime
    container.addElement(3);    //prime

    container2.addElement(169); //non-prime
    container2.addElement(89);  //prime
    container2.addElement(1);   //non-prime
    container2.addElement(11);  //prime
    container2.addElement(55);  //non-prime


    MagicalContainer::PrimeIterator primeIterator(container);
    MagicalContainer::PrimeIterator primeIterator2(primeIterator); // copy constructor
    MagicalContainer::PrimeIterator primeIterator3(container2);

    
    SUBCASE("Check on an empty container") {
        MagicalContainer::PrimeIterator primeIterator4(container3);
        CHECK(primeIterator4 == primeIterator4.end());
    }                

    SUBCASE("++ check") {
    ++primeIterator;
    CHECK((primeIterator!= primeIterator2));
    }

    SUBCASE("Check the smallest element of the container") {
        CHECK(*primeIterator.begin() == 17);                                // check if the smallest element is 17 in "container"
        CHECK(*primeIterator.begin() == *primeIterator2.begin());           // will be the same value "17" (copy constructor)
        CHECK(*primeIterator3.begin() == 89);                                // check if the smallest element is 89 in "container2"
    }      

    SUBCASE("Check the biggest element of the container") {             
        CHECK(*primeIterator.end() == 3);                           // check if the biggest element is 3 in "container"
        CHECK(*primeIterator.end() == *primeIterator2.end());       // will be the same value "3" (copy constructor)
        CHECK(*primeIterator3.end()== 11);                          // check if the biggest element is 11 in "container2"
    }   

    SUBCASE("Check order of sideCrossIterator") {             
        int TrueOrder[] = {17,2,3};
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == TrueOrder[0]);
        ++it;
        CHECK(*it == TrueOrder[1]);
        ++it;
        CHECK(*it == TrueOrder[2]);
    }
}