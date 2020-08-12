#pragma once

namespace InspurCloud
{
namespace OSS
{

    template<typename E, typename R>
    class Outcome
    {
    public:
        Outcome():success_(false), e_(), r_() 
        {
        }
        Outcome(const E& e) :success_(false), e_(e) 
        {
        }
        Outcome(const R& r): success_(true), r_(r)  
        {
        }
        Outcome(E&& e) : success_(false), e_(std::forward<E>(e))
        {
        } // Error move constructor
        Outcome(R&& r) : success_(true), r_(std::forward<R>(r)) 
        {
        } // Result move constructor
        Outcome(const Outcome& other) :
            success_(other.success_),
            e_(other.e_),
            r_(other.r_)
        {
        }
        Outcome(Outcome&& other):
            success_(other.success_),
            e_(std::move(other.e_)),
            r_(std::move(other.r_))
        {
            //*this = std::move(other);
        }
        Outcome& operator=(const Outcome& other)
        {
            if (this != &other) {
                success_ = other.success_;
                e_ = other.e_;
                r_ = other.r_;
            }
            return *this;
        }
        Outcome& operator=(Outcome&& other)
        {
            if (this != &other)
            {
                success_ = other.success_;
                r_ = std::move(other.r_);
                e_ = std::move(other.e_);
            }
            return *this;
        }

        bool isSuccess()const { return success_; }
        const E& error()const { return e_; }
        const R& result()const { return r_; }
        E& error() { return e_; }
        R& result() { return r_; }
    private:
        bool success_;
        E e_;
        R r_;
    };
}
}
