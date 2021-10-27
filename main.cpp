#include <iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void swap(char &c1,char &c2)
{
    char t=c1;
    c1=c2;
    c2=t;
}

string reverse(string &s)
{
//    string output;
    int n=s.length();
    for (auto i=0;i<(n/2);i++)
    {
         swap(s[i],s[n-i-1]);
    }

    return s;
}

string removePunctuation(const string &s,const string &punctuation)
{
    string output;
    int r=s.find(punctuation);
    output=s.substr(0,r);
    return output;
}

string makeLower(const string &s)
{
    string output;
    char lower;
    for(auto i=s.begin();i!=s.end();i++)
    {
        if((*i)>=65&&(*i)<=90)             //if alphabet case
        {
            lower=(*i)+32;                  //turn to lower case
            output=output+lower;
        }
        else
        {
            output=output+(*i);                   //remain same
        }
    }
    return output;
}

bool isPalin(const string &s)
{
    bool flag=false;
    int n=s.length();
    for(auto i=0;i<n;i++)
    {
        if(s[i]==s[n-i-1])
            flag=true;
        else
            flag=false;
    }
    return flag;
}



int main()
{
   string punc;
   vector<string> s;
   string z;
   string y;
   string x;
   ifstream infile;
   ofstream outfile;

   if(!outfile)
   {
       cout<<"Fileout fail"<<endl;
       exit(-1);
   }

   if(!infile)
   {
       cout<<"Filein fail"<<endl;
       exit(-1);
   }

   outfile.open("2.txt");      //user input string in 2.txt
   while(getline(cin,x))
   {
       outfile<<x<<endl;         //store string input in 2.txt
   }

   outfile.close();

   infile.open("2.txt");         //read from string of 2.txt of just now built

   outfile.open("2_out.txt");    //display result in 2_out.txt

   while(infile>>x)
   {
       y=makeLower(x);               //turn capital to lower case
/*       for(auto i=y.begin();i!=y.end();i++)
       {
           if((*i)>=97&&(*i)<=122)
               y=y+(*i);
           else
               punc=(*i);
       }*/
       z=removePunctuation(y,"?");
       s.push_back(reverse(z));     //reverse the string and push back into vector s
   }


   for(auto &elm:s)
   {
       if(isPalin(elm)==true)
       {
           cout<<"Yes"<<endl;
           outfile<<"Yes"<<endl;
       }

       else
       {
           cout<<"No"<<endl;
           outfile<<"No"<<endl;
       }

   }

   s.clear();
   infile.close();
   outfile.close();

    return 0;
}
