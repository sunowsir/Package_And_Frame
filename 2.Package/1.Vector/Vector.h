/*
 * File Name:    Vector.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月07日 星期四 11时18分31秒
 */

#ifndef _VECTOR_H
#define _VECTOR_H


#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

namespace Sunow_Vector_Lib {
    template <typename T>
    class Vector {
    private :
        T *data;
        int len;
        int data_len;
    public :
        Vector(int new_size = 1);
        ~Vector();
        bool insert(int pos, T new_data);
        bool insert_tail(T data);
        bool expand();
        int  length();
    };

    template <typename T>
    Vector<T>::Vector(int new_len) {
        this->T = new T[new_len];
        this->len = new_len;
        this->data_len = 0;
    }

    template <typename T>
    Vector<T>::~Vector() {
        if (this->data != NULL) delete[] this->data;
    }

    template <typename T>
    bool Vector<T>::insert(int pos, T new_data) {
        /* 插入位置非法 */
        if (pos < 0 || pos > this->len) {
            return false;
        }
        /* 插入最后的位置，扩容 */
        if (pos == this->size) {
            if (!expand()) return false;
        }
        this->data[pos] = new_data;
        this->data_len += 1;
        return true;
    }

    /* 扩容 */
    template <typename T>
    bool Vector<T>::expand() {
        T *temp_data = new T[this->data_len];
        if (memcpy(temp_data, this->data) == NULL) return false;
        delete[] this->data;
        this->data = new T[this->data_len + 5];
        if (memcpy(this->data, temp_data) == NULL) return false;
        delete[] temp_data;
        return true;
    }

    /* 返回已用长度 */

    template <typename T>
    int Vector<T>::length() {
        return this->data_len;
    }
}



#endif
