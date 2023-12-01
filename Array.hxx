#ifndef ARRAY_HXX
#define ARRAY_HXX
#include <cstddef>
template<typename T, size_t S>
class Array {
    public:
        Array(){

        }
        constexpr size_t size() const {
            return S;
        }

        /// @brief 
        /// @param index 
        /// @return 
        T& operator[](size_t index) {
            return m_Data[index];
        }
        const T& operator[](size_t index) const{
            return m_Data[index];
        }
        T* Data() {
            return m_Data;
        }
        const T* Data() const {
            return m_Data;
        }
    private:
        T m_Data[S];
};

#endif // ARRAY_HXX