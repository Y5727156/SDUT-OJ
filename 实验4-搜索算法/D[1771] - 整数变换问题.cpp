#include <iostream>
using namespace std;
int k = 1;
int c = 0;
char a[100] = {'\0'};
int SelectFun(const int n, const int m, int s) //选择函数
{
     if(s == 0){
        return 3 * n;
     }

     else{
        return n / 2;
     }

}
bool DeptSearch(int Dept, const int n, const int m)//深搜
{
     int num;
     if(Dept > k) return false;
     num = n;
     for(int i = 0; i < 2; i++)
     {
          num = SelectFun(n, m, i);
          if(num  == m || DeptSearch(Dept + 1,num,m)){

                if(i == 0){
                    a[c] = 'f';
                }
                else{
                    a[c] = 'g';
                }
                c ++;
                return true;
          }

     }
     return false;
}

int main()
{
    int m, n, Dept = 1;
    cin >> m >> n;
    k = 1;
    while( !DeptSearch(1, m, n) )
    {
        k ++;
    }
    cout << k << endl;
    int i = 0;
    for(i = 0; i < c; i ++){
        cout << a[i];
    }
    return 0;
}

Sample Input

15 4

Sample Output

4
gfgg


