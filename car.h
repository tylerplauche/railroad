#ifndef RAILROAD_CAR_H
#define RAILROAD_CAR_H


struct Car
{
    unsigned int id;
    Car() : id(0) {}
    ~Car() {}

    bool operator==(const Car car) { return this->id == car.id; }
    bool operator!=(const Car car) { return this->id != car.id; }

    /** Return the Car as a string */
    string toString() const
    {
        stringstream out;
        out << id;
        return out.str();
    } // end toString()

    /** Make insertion operator friend for a Car */
    friend std::ostream& operator<< (ostream& os, const Car& c)
    {
        os << c.toString();
        return os;
    } // end operator<<
};


#endif //RAILROAD_CAR_H
