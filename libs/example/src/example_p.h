#ifndef EXAMPLE_P_H
#define EXAMPLE_P_H

namespace example
{
    
    class TogglerImpl {
    public:
        TogglerImpl(bool value) : value(value) {}
        bool value;
    };

}

#endif // EXAMPLE_P_H
