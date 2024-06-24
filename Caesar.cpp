#include <iostream>
using namespace std;
#include <string>


string Caesar(string text, int key, bool encrypt)
{
    string ret;
    string::iterator it;
    if(encrypt)
    {
        for(it = text.begin() ; it != text.end() ; it++)
        {
            if(*it>='a' && *it<='z')
            {
                ret.push_back(*it+=key);
                if(*it>'z')
                {
                    ret.pop_back();
                    ret.push_back(*it+key-26);
                }
            }

            else if(*it>='A' && *it<='Z')
            {
                ret.push_back(*it+=key);
                if(*it>'Z')
                {
                    ret.pop_back();
                    ret.push_back(*it+key-26);
                }
            }


            else if(*it>='0' && *it<='9')
            {
                ret.push_back(*it+=key);
                if(*it>'9')
                {
                    ret.pop_back();
                    ret.push_back(*it+key-10);
                }
            }

            else
            {
                ret.push_back(*it);
            }

            
        }
    }

    else
    {
        for(it = text.begin() ; it != text.end() ; it++)
        {
            if(*it>='a' && *it<='z')
            {
                ret.push_back(*it-=key);
                if(*it<'a')
                {
                    ret.pop_back();
                    ret.push_back(*it+key+26);
                }
            }

            else if(*it>='A' && *it<='Z')
            {
                ret.push_back(*it-=key);
                if(*it<'A')
                {
                    ret.pop_back();
                    ret.push_back(*it+key+26);
                }
            }


            else if(*it>='0' && *it<='9')
            {
                ret.push_back(*it-=key);
                if(*it<'0')
                {
                    ret.pop_back();
                    ret.push_back(*it+key+10);
                }
            }

            else
            {
                ret.push_back(*it);
            }
        }

    }

    return ret;
}

int main()
{
    string text,ret;
    int key,op;

    cout<<"\n--------------- Commands ---------------\n";
    cout<<"Press 1 for Encrpytion\n";
    cout<<"Press 0 for Decrpytion\n";
    cin>>op;
    cout<<"\nEnter Key: ";
    cin>>key;
    if(op)
    {
        cout<<"Enter Plain Text: ";
        getline(cin,text);
        getline(cin,text);
        ret = Caesar(text,key,op);
        cout<<"Cipher Text: "<<ret <<endl;
    }

    else
    {
        cout<<"Enter Cipher Text: ";
        getline(cin,text);
        getline(cin,text);
        ret = Caesar(text,key,op);
        cout<<"Plain Text: "<<ret <<endl;
    }
    
    return 0;
}
