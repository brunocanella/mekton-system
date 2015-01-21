#ifndef MEMORY_UTILS_HPP
#define MEMORY_UTILS_HPP

#include <memory>

/**
 * @brief Creates a pointer of the given class and wraps it around a shared_ptr.
 *
 * This is a syntax sugar function that can be used to simplify the way shared pointers are created.
 *
 * @template Type The class of the pointer that will be created.
 * @template Args The variadic arguments type.
 * @param a_args The values of the variadic arguments
 *
 * @usage new_shared_ptr<SomeClass>( arg1, arg2, arg3, ... );
 */
template<typename Type, typename... Args > std::shared_ptr<Type> new_shared_ptr( Args... a_args ) {
	return std::shared_ptr<Type>( new T( a_args... ) );
}

#endif // MEMORY_UTILS_HPP

