
template<class T>
struct vec2
{
    T x;
    T y;
    vec2() = default;
    vec2(T x, T y) : x(x), y(y) {}
    vec2<T> operator+(const vec2<T>& rhs)
    {
        vec2<T> res;
        res.x = x + rhs.x;
        res.y = y + rhs.y;
        return res;
    }
    vec2<T> operator+=(const vec2<T>& rhs)
    {
        return *this + rhs;
    }
    vec2<T> operator-(const vec2<T>& rhs)
    {
        vec2<T> res;
        res.x = x - rhs.x;
        res.y = y - rhs.y;
        return res;
    }
    vec2<T> operator-=(const vec2<T>& rhs)
    {
        return *this - rhs;
    }
};

typedef vec2<int> vec2i;
