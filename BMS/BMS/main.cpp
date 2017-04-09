#include <iostream>
#include <clocale>

using namespace std;

void ShiftBM(char *mass, int mass_l, char *templa, int templa_l, char *alphabet, int alphabet_l, int *prfx)
{
    int sgn = 0;
    int count = 0;
    for(int i = mass_l-1; i >= 0; i--)
    {
        for(int n = alphabet_l-1; n >= 0; n--)
        {
            if(mass[i] == alphabet[n] && prfx[n] < 0)
            {
                prfx[n] = mass_l - i - 1;
                count = n;
            }
        }
        
        if(count != 0){
            for(int n = 0; n < templa_l; n++)
            {
                if(templa[n] == alphabet[count])
                    sgn = 1;
            }
            if(sgn == 0)
            {
                prfx[count] = templa_l;
            }
            count = 0;
            sgn = 0;
        }
    }
}

int alphabetcnt(char *mass, int mass_l, char *alphabet)
{
    int alphabet_l = 0;
    int sgn = 0;
    for(int i = 0; i < mass_l; i++)
    {
        for(int n = 0; n < alphabet_l; n++)
        {
            if(alphabet[n] == mass[i])
            {
                sgn = 1;
            }
        }
        if(sgn == 0)
        {
            alphabet[alphabet_l] = mass[i];
            alphabet_l++;
        }
        sgn = 0;
    }
    return alphabet_l;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int count;
    
    char *mass = new char[255];
    char *templa = new char[255];
    int *prfx = new int[255];
    int *result = new int[255];
    char *alphabet = new char[255];
    
    
    gets(mass);
    cin >> templa;
    
    int templa_l = strlen(templa);
    int mass_l = strlen(mass);
    
    int word;
    int sign = templa_l-1;
    int sovpad = 0;
    int i = 0;
    int flag = 0;
    int word1;
    
    word = alphabetcnt(mass, mass_l, alphabet);
    ShiftBM(mass, mass_l, templa, templa_l, alphabet, word, prfx);
    
    while(sign < mass_l)
    {
        cout << mass[sign] << "|" << templa[templa_l-1] << "|" << sign << endl;
        if(mass[sign] == templa[templa_l-1])
        {
            cout << "@" << endl;
            for(int n = 0; n < templa_l; n++)
            {
                if(mass[sign-n] != templa[templa_l-n-1])
                {
                    if(flag != 1){
                        for(int i = 0; i < word; i++)
                        {
                            if(alphabet[i] == mass[sign-n])
                                word1 = i;
                        }
                        sovpad = prfx[word1];
                        cout << "#" << sovpad << "#" << endl;
                    }
                    flag = 1;
                }
            }
            if(flag == 0)
                cout << "Совпадение с " << sign-templa_l+1 << endl;
            flag = 0;
            cout << "#" << sovpad << "#" << endl;
        }
        else
        {
            for(int i = 0; i < word; i++)
            {
                if(alphabet[i] == mass[sign])
                    word1 = i;
            }
            if(mass[sign+1] == templa[templa_l-1])
                sovpad = 1;
            else
                sovpad = prfx[word1];
            cout << "#" << sovpad << "#" << endl;
        }
        i++;
        if(sovpad == 0)
            sovpad++;
        sign += sovpad;
    }
    return 0;
}
