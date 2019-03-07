/*
 * File Name:    LinkList.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月07日 星期四 15时10分07秒
 */

#include <iostream>
#include <string>
using std::string;

namespace Sunow_LinkList_Lib {
    template <typename T>
    class LinkList {
    private : 
        struct Node {
            T *data;
            struct Node *next, *prev;
        };
        Node *head;
        int length;
        Node *get_new_node(T new_data) {
            Node *new_node = new Node;
            new_node->data = new T(new_data);
            new_node->next = NULL;
            new_node->prev = NULL;
            return new_node;
        }
    public : 
        LinkList (int new_length = 0);
        ~LinkList();
        /* 
         * "" : change data at 'pos'; 
         * "prev" : insert data at 'pos - 1'; 
         * "next" : insert data at 'pos + 1'
         * */
        bool insert(T new_data, int pos, string opera = "" ); 
        bool erase(T data_or_pos, string opera = "data");
        int  search(T search_data);
        bool reverse();
    };

}

template <typename T>
Sunow_LinkList_Lib::LinkList<T>::LinkList(int new_length) {
    this->head = new Node;
    this->head.data = NULL;
    this->head.next = this->head;
    this->head.prev = this->head;
    this->length = new_length;
}

template <typename T>
Sunow_LinkList_Lib::LinkList<T>::~LinkList() {
    if (this->head->next == this->head) {
        delete this->head;
        return ;
    }
    Node *current_node = this->head->next;
    while (current_node->next != this->head) {
        current_node = current_node->next;
        delete current_node->prev->data;
        delete current_node->prev;
    }
    delete this->head;
}

template <typename T>
bool Sunow_LinkList_Lib::LinkList<T>::insert(T new_data, int pos, string opera) {
    Node current_node  = this->head->next;
    int now_pos = 0;
    while (now_pos < pos - 1 && current_node->next != head) {
        current_node = current_node->next;
    }
    if (current_node->next == head && now_pos + 1 != pos) {
        return false;
    }
    switch (opera) {
        case "" : {
            current_node->next->data = new_data;
            return true;
            break;
        }
        case "next" : {
            pos += 1;
            break;
        }
    }
    Node *insert_node = get_new_node(new_data);
    current_node->next->prev = insert_node;
    insert_node->next = current_node->prev;
    current_node->next = insert_node;
    insert_node->prev = current_node;
    this->length++;
    return true;
}

template <typename T>
bool Sunow_LinkList_Lib::LinkList<T>::erase(T data_or_pos, string opera) {
    switch (opera) {
        case "data" : {
            T delete_data = data_or_pos;
        }
        case "pos" : {
            int pos = data_or_pos;
            if (pos < 0 && pos > this->length) return false;
            Node *current_node = this->head->next;
            int now_pos = 0;
            while (now_pos < pos && current_node->next != this->head) {
                current_node = current_node->next;
            }

        }
    }
    return true;
}
