#pragma once

// CoreHandle
#include "CoreHandle_Utils.h"

NS_COREHANDLE_BEGIN

template <typename T>
struct HandleTraits
{
    //------------------------------------------------------------------------//
    // Type Aliases                                                           //
    //------------------------------------------------------------------------//
public:
    using Type = T;

    //------------------------------------------------------------------------//
    // Static Methods                                                         //
    //------------------------------------------------------------------------//
public:
    static Type Invalid() noexcept
    {
        return nullptr;
    }

    static bool Equals(const Type &lhs, const Type &rhs) noexcept
    {
        return lhs == rhs;
    }

    //
    //static void Close(Type t);
};

NS_COREHANDLE_END
