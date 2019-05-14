#pragma once

namespace itertools{


template <typename T>
class powerset
{
    public:
    T group;

    powerset(T a) : group(a){}

    class iterator{
        T _start;

    public:
        iterator(T start) : _start(start){}

    };

    auto begin(){
        return group.begin();
    }

    auto end(){
        return group.end();
    }
};
}
