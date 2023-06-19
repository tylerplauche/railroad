#ifndef RAILROAD_DEQUEINTERFACE_H
#define RAILROAD_DEQUEINTERFACE_H

template<typename T>
class dequeInterface {
private:
    //static const size_t DEFAULT_CAPACITY = 4;
public:

     dequeInterface(void){}
     ~dequeInterface(void){}
    virtual void push_front(const T&) = 0;
    virtual void push_back(const T&) = 0;
    virtual void reallocate() = 0;
    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual T& front() = 0;
    virtual T& back() = 0;
    virtual bool empty() const;
    virtual T& at(size_t) = 0;
    virtual std::string toString() const;

};

#endif //RAILROAD_DEQUEINTERFACE_H
