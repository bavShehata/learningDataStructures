#include <iostream>
using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;

public:
    Product(){};
    Product(int i, string n, double p)
    {
        id = i;
        name = n;
        price = p;
    }
    void display()
    {
        cout << id << " " << name << " " << price << endl;
    }
    double getPrice() { return price; }
};
class Node
{
private:
    Product data;
    Node *next;

public:
    Node()
    {
        next = nullptr;
    }
    void setData(Product p) { data = p; }
    Product getData() { return data; }
    Node *getNextNode() { return next; }
    void setNextNode(Node *n) { next = n; }
};

class SLL
{
private:
    Node *head;

public:
    SLL()
    {
        head = nullptr;
    }
    Node *getHead() { return head; }
    void append(Product p)
    {
        Node *newProduct = new Node();
        newProduct->setData(p);
        if (head == nullptr)
        {
            head = newProduct;
        }
        else
        {
            Node *temp = head;
            while (temp->getNextNode() != nullptr)
            {
                temp = temp->getNextNode();
            }
            temp->setNextNode(newProduct);
        }
    }
    void remove(Node *n)
    {
        Node *temp = head;
        Node *prevNode = nullptr;
        if (head == n)
        {
            delete temp;
            head = head->getNextNode();
            return;
        }
        while (temp->getNextNode() != nullptr)
        {
            prevNode = temp;
            temp = temp->getNextNode();
            if (temp == n)
            {
                prevNode->setNextNode(temp->getNextNode());
                cout << "deleted " << temp->getData().getPrice() << endl;
                delete temp;
                break;
            }
        }
    }
    void display()
    {
        Node *temp = head;
        if (temp != nullptr)
            while (temp != nullptr)
            {

                cout << temp << endl;
                temp->getData().display();
                temp = temp->getNextNode();
            }
        else
        {
            cout << "List is empty\n";
        }
    }
};
class Store
{
private:
    SLL products;
    Node *node;

public:
    void addProduct(Product p)
    {
        products.append(p);
    }
    void display()
    {
        products.display();
    }
    void sort()
    {
        SLL sorted;
        Node *leastNode;
        while (products.getHead() != nullptr)
        {
            double least = products.getHead()->getData().getPrice();

            Node *temp = products.getHead();
            while (temp != nullptr)
            {
                if (least > temp->getData().getPrice())
                {
                    leastNode = temp;
                    least = temp->getData().getPrice();
                }
                temp = temp->getNextNode();
            }
            if (least == products.getHead()->getData().getPrice())
            {
                sorted.append(products.getHead()->getData());
                products.remove(products.getHead());
            }
            else
            {
                sorted.append(leastNode->getData());
                products.remove(leastNode);
            }
        }
        products = sorted;
    }
};

int main()
{
    int x = 0;
    int id;
    string name;
    double price;
    Store store;

    store.addProduct(Product(1, "a", 2));
    store.addProduct(Product(2, "b", 3));
    store.addProduct(Product(3, "c", 1));
    store.sort();
    store.display();
    return 0;
}