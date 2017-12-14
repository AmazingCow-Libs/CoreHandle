#pragma once

// AmazingCow Libs
#include "CoreAssert/CoreAssert.h"
// CoreHandle
#include "CoreHandle_Utils.h"
#include "HandleTraits.h"

//----------------------------------------------------------------------------//
// Handle                                                                     //
//----------------------------------------------------------------------------//
NS_COREHANDLE_BEGIN

template <typename Traits>
class Handle
{
    //------------------------------------------------------------------------//
    // Type Aliases                                                           //
    //------------------------------------------------------------------------//
public:
    using Type = decltype(Traits::Invalid());


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    explicit Handle(Type value = Traits::Invalid()) noexcept :
        m_value(value)
    {
        // Empty...
    }

    Handle(const Handle &) noexcept = delete;

    Handle(Handle &&other) noexcept :
        m_value(other.Detach())
    {
        // Empty...
    }

    ~Handle() noexcept
    {
        Close();
    }


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    Handle& operator=(const Handle &) noexcept  = delete;

    Handle& operator=(Handle &&other) noexcept
    {
        if(this != &other)
            Reset(other.Detach());

        return *this;
    }

    explicit operator bool() const noexcept
    {
        auto invalid = Traits::Invalid();
        auto result = Traits::Equals(m_value, invalid);
        return !result;
    }


    //------------------------------------------------------------------------//
    // Public Methods                                                         //
    //------------------------------------------------------------------------//
public:
    Type Get() const noexcept
    {
        return m_value;
    }

    Type* Set() noexcept
    {
        auto s = !(*this);
        COREASSERT_ASSERT(
            !(*this),
            "Trying to set an already owned handle"
        );

        return &m_value;
    }

    Type Detach() noexcept
    {
        auto value = m_value;
        m_value    = Traits::Invalid();

        return value;
    }

    Type Reset(Type value = Traits::Invalid()) noexcept
    {
        if(m_value != value)
        {
            Close();
            m_value = value;
        }

        return m_value;
    }

    void Swap(Handle<Traits> &other)
    {
        auto temp     = m_value;
        m_value       = other.m_value;
        other.m_value = temp;
    }


    //------------------------------------------------------------------------//
    // Private Methods                                                        //
    //------------------------------------------------------------------------//
private:
    void Close() noexcept
    {
        if(*this)
        {
            Traits::Close(m_value);
        }
    }

    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    Type m_value = Traits::Invalid();
};


//----------------------------------------------------------------------------//
// Swap Function                                                              //
//----------------------------------------------------------------------------//
template <typename Traits>
void swap(Handle<Traits> &lhs, Handle<Traits> &rhs) noexcept
{
    lhs.Swap(rhs);
}


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
template <typename Traits>
inline bool operator==(
    const Handle<Traits> &lhs,
    const Handle<Traits> &rhs) noexcept
{
    return lhs.Get() == rhs.Get();
}

template <typename Traits>
inline bool operator!=(
    const Handle<Traits> &lhs,
    const Handle<Traits> &rhs) noexcept
{
    return !(lhs == rhs);
}

NS_COREHANDLE_END
