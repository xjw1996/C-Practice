//**2）vector <vector> kk;//int指针的向量**
//#include<iostream>  
//#include<vector>  
//using namespace std;
//int main()
//{
//    vector<int*> k;
//    int* p = new int[15];
//    for (int j = 0; j < 15; j++)
//    {
//        p[j] = j;
//        k.push_back(&p[j]);
//    }
//    for (int i = 0; i < 15;i++)
//    {
//        cout << *k[i] << " ";//因为向量容器里面都是int型的指针变量，  
//    }                           //所以值都是指针，所以需要间接访问运算符*  
//    delete[]p;
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector< vector<int>* >* pvv;
    //pvv.resize(10);
    pvv = new vector< vector<int>* >();
    pvv->push_back(new vector<int>(4));
    pvv->push_back(new vector<int>(4));
    pvv->push_back(new vector<int>(4));

    /* ↓だと各列が同じポインタを参照してしまう。
    vector< vector<int>* >* pvv;
    pvv = new vector< vector<int>* >(3, new vector<int>(4));
    // スタックに確保したときにうまくいくのはコピーされるから？
    */

    /* ↓だとスタックにメモリが確保される気が…
    vector< vector<int> >* pvv;
    pvv = new vector< vector<int> >(3, vector<int>(4));
    */

    pvv->at(0)->at(0) = 100;
    pvv->at(0)->at(1) = 101;
    pvv->at(0)->at(2) = 102;
    pvv->at(0)->at(3) = 103;
    pvv->at(1)->at(0) = 110;
    pvv->at(1)->at(1) = 111;
    pvv->at(1)->at(2) = 112;
    pvv->at(1)->at(3) = 113;
    pvv->at(2)->at(0) = 120;
    pvv->at(2)->at(1) = 121;
    pvv->at(2)->at(2) = 122;
    pvv->at(2)->at(3) = 123;

    /*for (vector< vector<int>* >::iterator i = pvv->begin(); i != pvv->end(); i++) {
        for (vector<int>::iterator j = (*i)->begin(); j != (*i)->end(); j++) {
            cout << *j << endl;
        }
    }*/

    /*for (vector< vector<int>* >::iterator i = pvv->begin(); i != pvv->end(); i++) {
        vector<int>* v = *i;
        delete v;
    }*/

    //delete pvv;

    for (vector< vector<int>* >::iterator i = pvv->begin(); i != pvv->end(); i++) {
        for (vector<int>::iterator j = (*i)->begin(); j != (*i)->end(); j++) {
            cout << *j << endl;
        }
    }
    return 0;
}

