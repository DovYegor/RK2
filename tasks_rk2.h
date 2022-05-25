#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

//task1
struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    std::list<Node*> listChilds;
    int name;
    static int countNodes;
};

class Graph {
    private :
        Node* head;
        //����� ����� ������ ����� �������, ������� ����� ������������
    public :
        Graph();
        Graph(int countNodes);
        ~Graph();
        /*
            output		:	-1 - ���� ������� �� �����������
                        :	������������� ����� -- ����� �����
            author		:
            date		:
            version		:
        */
        int buildTreeBFS(int countNodes);
        /*
            output		:	-1 - ���� ������� �� �����������
                        :	������������� ����� -- ����� �����
            author		:
            date		:
            version		:
        */
        int buildTreeDFS(int countNodes);
        /*
            description	:	����� ����� � ������ ������ � ����
            input		:
            output		:
            author		:
            date		:
            version		:
        */
        void BFS();
        void DFS();
        /*
            description	:	������� ������ ���� �� ��� �����,
                            DFS - � ���� ����� ������
                            BSD - � ���� ����� ��������
            input 		:	nameNode -- ��� ����
            output		:	{bool -- ���� �����, list<int> -- ������ ��� ����� �� ������������}
            description	:	��������� DFS -- ����� � �������, BSF -- ����� � ������
            author		:
            date		:
            version		:
        */
        std::pair<bool, list<int>> searchDFS(int nameNode);
        std::pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo {
    private :
        T* ar;	//������
        int size;	//������ �������
        int countData;	//����� ��������� � �������
    public :
        Filo() {
            T* ar = new T[100];
            int countData = 0;
            int size = 100;
        }
        Filo(int _size) {
            T* ar = new T[_size];
            int countData = 0;
            int size = _size;
        }
        ~Filo() {
            delete[] ar;
        }

        /*
            input		:	������� ������� ���� ��������
            output		:	1 - ������� ��������, 0 - ������� �� ��������
            description	:	���������� �������� � ����� �������
        */
        int push_back(T el) {
            if (countData==size)
                return 0;
            ar[countData] = el;
            countData++;
            return 1;
        }


        /*
            input		:	������� ������� ���� ��������
            output		:	����
                            �������� ������� ��������� ����
                                1 - ������� ������� ��������, 0 - ��������� � ������� ���
                            �������� ������� ��������� ���� -- ��� ����������� �������
            description	:	���������� �������� �� �������
        */
        pair<int,T> pop_back() {
            pair<int,T> p;
            if (countData<=0){
                p.first = 0;
                p.second = 0;
                return p;
            }
            countData--;
            p={1,ar[countData]};
            return p;
        }


        /*
            input		:	������� ������� ���� ��������
            output		:	����
                            �������� ������� ��������� ����
                                1 - ������� ������� ��������, 0 - ��������� � ������� ���
                            �������� ������� ��������� ���� -- ��� ����������� �������
            description	:	���������� �������� �� �������
        */
        void returnAr() { }
};

//task4
template<class T>
    std::ostream& operator << (std::ostream& os, const pair<int,T> temp){
        os << "(" << temp.first << ", " << temp.second << ")" << std::endl;
        return os;
    }

//task5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //����� ���������� ����� ���������� � �������

public :
    CheckBrackets() : Filo<char>() {
        char* ar = new char[1000];
        int countData = 0;
        int size = 1000;
    }
    ~CheckBrackets() {
        /*delete[] ar;*/
    }
    /*
        input		:	������ �� ��������
        output		:	0 - �� ������, -1 - ������ �� �������
        description	:	�������� ������
    */
    int checkBrackets(const char* strBrackets) {
        for (int i = 0; i < strlen(strBrackets); i++){
            if (strBrackets[i] == '{' || strBrackets[i] == '(' || strBrackets[i] == '['){
                push_back(strBrackets[i]);
            }
            if (strBrackets[i] == '}'){
                pair<int,char> cur;
                cur = pop_back();
                char temp = cur.second;
                if (temp != '{')
                    return -1;
            }
            if (strBrackets[i] == ')'){
                pair<int,char> cur;
                cur = pop_back();
                char temp = cur.second;
                if (temp != '(')
                    return -1;
            }
            if (strBrackets[i] == ']'){
                pair<int,char> cur;
                cur = pop_back();
                char temp = cur.second;
                if (temp != '[')
                    return -1;
            }
        }
        pair<int,char> cur;
        cur = pop_back();
        char temp = cur.second;
        if (temp != 0)
            return -1;
        return 0;
    }
};
