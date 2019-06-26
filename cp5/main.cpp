//
//  main.cpp
//  cp0
//
//  Created by s20181102936 on 2019/6/20.
//  Copyright © 2019 s20181102936. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct stu{
    char num[4];
    char name[20];
    float a[8]={0};
    float s;
}st[10];
int main()
{
    int n,k;
    ifstream putin1("/Users/s20181102936/Desktop/student.txt");
    ifstream putin2("/Users/s20181102936/Desktop/caipan.txt");
    ofstream putout ("/Users/s20181102936/Desktop/score1.txt ");
    if(putin1.is_open())
    {
        if(putin2.is_open())
        {
            for(k=0;k<3;k++)
            {
                putin1>>st[k].num>>st[k].name;
                cout<<"  "<<st[k].num<<" "<<st[k].name<<endl;
                for (int i=0;i<7;i++)
                {
                    putin2>>st[k].a[i];
                    cout<<st[k].a[i]<<" ";
                }
                cout<<endl;
            }
            putin2.close();
        }
        putin1.close();
    }
    if(putout.is_open())
    {
        for(k=0;k<3;k++)
        {
            for (int i=0;i<7;i++)
            {
                for(int j=1;j<7;j++)
                    if(st[k].a[j-1]>st[k].a[j])
                    {
                        n=st[k].a[j-1];
                        st[k].a[j-1]=st[k].a[j];
                        st[k].a[j]=n;
                    }
            }
            
        }
        for(k=0;k<3;k++){
            st[k].s=0;
            for (int i=1;i<6;i++)
            {
                
                st[k].s+=st[k].a[i];
            }
        }
        int m,r;
        int b[10];
        r=0;
        m=st[k].s;
        for(r=0;r<3;r++){
            b[r]=r;
        }
        for(k=0;k<3;k++){
            for(int j=1;j<3;j++)
            {
                if(st[j-1].s>st[j].s)
                {
                    m=b[j-1];
                    b[j-1]=b[j];
                    b[j]=m;
                }
            }
        }
        for(k=0;k<3;k++){
            
            putout<<st[b[k]].num<<" "<<st[b[k]].name<<" ";
            for (int i=1;i<6;i++)
            {
                putout<<st[b[k]].a[i]<<" ";
                
            }
            putout<<st[b[k]].s/5<<endl;
        }
        
        putout.close();
    }
    return 0;
}

