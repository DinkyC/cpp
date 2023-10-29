#include <type_traits> // for std::is_constant_evaluated

constexpr int someFunction()
{
    if (std::is_constant_evaluated()) { // if compile-time evaluation
        return someConstexprFcn(); // calculate some value at compile-time
    }
    else { // runtime evaluation
        return someNonConstexprFcn(); // calculate some value at runtime
    }
}
