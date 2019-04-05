#include <iostream>
#include <chrono>
#include <utility>

/*!
 *  Narzedzie do zliczania czasu
 *
 *  Sposob uzycia:
 *
 *  {
 *    Benchmark<std::chrono::nanoseconds> b;
 *    // kod do zbadania
 *    size_t elapsed = b.elapsed();
 *  }
 *
 *  lub
 *
 *  {
 *    Benchmark<std::chrono::milliseconds> b(true);
 *    // kod do zbadania
 *  } // obiekt wypisze wartosc czasu w podanych jednostkach na stderr
 */
template<typename D = std::chrono::microseconds>
class Benchmark {
public:

    Benchmark(bool printOnExit = false) : m_print(printOnExit) {
        start = std::chrono::high_resolution_clock::now();
    }
    typename D::rep elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<D>(end-start);
        return result.count();
    }
    ~Benchmark() {
        auto result = elapsed();
        if (m_print)
        {
            std::cerr << "Czas: " << result << "\n";
        }
    }
private:
    std::chrono::high_resolution_clock::time_point start;
    bool m_print = true;
};




/*
 * Slownik
 *
 */
template<typename KeyType, typename ValueType>
class TreeMap
{
  public:
    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;

    TreeMap() = default;    // konstruktor trywialny
    ~TreeMap() = default;   // destruktor trywialny

    /*!
     * true jezeli slownik jest pusty
     */
    bool isEmpty() const
    {
        throw std::runtime_error("TODO: isEmpty");
    }

    /*!
     * dodaje wpis do slownika
     */
    void insert(const key_type& key, const mapped_type &value)
    {
        throw std::runtime_error("TODO: insert");
    }

    /*!
     * dodaje wpis do slownika przez podanie pary klucz-wartosc
     */
    void insert(const value_type &key_value)
    {
        throw std::runtime_error("TODO: insert");
    }

    /*!
     * zwraca referencje na wartosc dla podanego klucza
     *
     * jezeli elementu nie ma w slowniku, dodaje go
     */
    mapped_type& operator[](const key_type& key)
    {
        if(!root) return nullptr;

       splay(root, key);
       if(root->key == key)
            return root->value;

        else throw std::runtime_error("No value under this key"); // to change later

    }

    /*!
     * zwraca wartosc dla podanego klucza
     */
    const mapped_type& value(const key_type& key) const
    {
       if(!root) return nullptr;

       splay(root, key);
       if(root->key == key)
            return root->value;

        else throw std::runtime_error("No value under this key");

    }

    /*!
     * zwraca informacje, czy istnieje w slowniku podany klucz
     */
    bool contains(const key_type& key) const {
        throw std::runtime_error("TODO: contains");
    }

    /*!
     * zwraca liczbe wpisow w slowniku
     */
    size_t size() const {
        throw std::runtime_error("TODO: size");

    }

    void rotateLeft(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;

        if(y->left!=nullptr)
            y=left->parent=x;

        if(x==root)
            root=y;

        else if(x==x->parent->left)
            x->parent->left =y;

        else
        x->parent->right =y;

        y->left=x;
        x->parent=y;

    }

    void rotateRight(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;

        if(y->right!=nullptr)
            y=right->parent=x;

        if(x==root)
            root=y;

        else if(x==x->parent->left)
            x->parent->left = y;

        else
        x->parent->right =y;

        y->right=x;
        x->parent=y;

    }


    Node* newNode(key_type tkey, mapped_type tvalue = 0)
    {
        Node* newNode = new Node;
        newNode->left= nullptr; newNode->right= nullptr;

        newNode->value = tvalue;

         newNode->key = tkey;

        return newNode;


    }


    Node * splay(Node *root, key_type k)
    {
        if(!root)
            return nullptr;

    Node * x = root;

    while(1)
    {
        if(x->key == k)
            {
                break;
            }

        if(x->key < k)
            {
                if(x->right)
                    break;

                else
                x=x->right;
                continue;
            }

        if(x->key > k)
            {
                if(x->left)
                    break;


                x=x->left;
                continue;

            }


    }





    while(1)
    {
     //x is a child of root
     if(x->parent = root)
     {
        if(x==x->parent->left)
            rotateRight(x->parent);

         else if(x==x->parent->right)
            rotateLeft(x->parent);

      return root;

     }

    //zig zig
     if(x==x->parent->left && x->parent == x->parent->parent->left)
        {
            rotateRight(x->parent->parent);
            rotateRight(x->parent);
            continue;

        }

    if(x==x->parent->right && x->parent == x->parent->parent->right)
        {
            rotateLeft(x->parent->parent);
            rotateLeft(x->parent);
           continue;
        }

    //zig zags
    if(x==x->parent->left && x->parent == x->parent->parent->right)
        {
            rotateRight(x->parent);
            rotateLeft(x->parent);
            continue;
        }

    if(x==x->parent->right && x->parent == x->parent->parent->left)
        {
            rotateLeft(x->parent);
            rotateRight(x->parent);
            continue;
        }

}


    }

private:


class Node{


Node *parent, *left, *right

key_type key;
mapped_type value;



}

};

#include "tests.h"

int main()
{
    unit_test();

    return 0;
}
