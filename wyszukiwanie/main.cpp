#include <bits/stdc++.h>
#define d 256
# define NO_OF_CHARS 256
using namespace std;

/**Silowo**/
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int licznik=0;
    int licznikPorownan=0;

    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++) {
            licznikPorownan++;
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M){
            cout << i+1 << endl;
            licznik++;
        }
    }

    cout<<"Znaleziony silowo: "<<licznik<<endl;
    cout<<"Liczba porownan silowo: "<<licznikPorownan;

}


/**KMP**/
void computeLPSArray(char* pat, int M, int* lps);
void searchKMP(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int licznik=0;
    int licznikPorownan=0;

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
            licznikPorownan++;
        }

        if (j == M) {
            cout<< (i - j )+1<<endl;
            licznik++;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    cout<<"Znaleziony KMP: "<<licznik<<endl;
    cout<<"Liczba porownan KMP: "<<licznikPorownan;
}


void computeLPSArray(char* pat, int M, int* lps)
{

    int len = 0;

    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

}

/**Rabin-Karp**/
void searchRK(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int licznik=0;
    int licznikPorownan=0;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;


    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                licznikPorownan++;
                if (txt[i+j] != pat[j])
                    break;
            }

            if (j == M) {
                cout << i + 1 << endl;
                licznik++;
            }
        }

        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            if (t < 0)
                t = (t + q);
        }
    }
    cout<<"Znaleziony RK: "<<licznik<<endl;
    cout<<"Liczba porownan RK: "<<licznikPorownan;
}

/**Boyer Moore**/
void badCharHeuristic( string str, int size,
                       int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void searchBM( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int licznik=0;
    int licznikPorownan=0;
    int badchar[NO_OF_CHARS];


    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;

        while(j >= 0 && pat[j] == txt[s + j])
        {
            j--;
            licznikPorownan++;
            }

        if (j < 0)
        {
            cout<<  s +1  << endl;
            licznik++;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    cout<<"Znaleziony BM: "<<licznik<<endl;
    cout<<"Liczba porownan BM: "<<licznikPorownan;
}
int main()
{
    char txt[] = "ababrakabrabarrbbbbabkkabrakabrabarrbarrabrakabrabakkkbabrakabrabakbkkarbrbbrkabrakabrabaabrakabrababaabrakabrabaabrakabrabaabrakabrabaarkrkbkkabrakabrabarrakarkbabrakabrababbabrakabrabarakbabrakabrabaakkkrkarakabrakabrabakabrakabrabakbkaabrakabrabakararabrakabrabaabrakabrababkabaabrakabrababbabrakabrababrkrrabrakabrabakbkrbkabrakabrabaarbkkabrakabrabarabkkaabrkbabrakabrabarrababrakabrabaaakabrakabrababarrbkkabrakabrabakakrarabrakabrabararbbbrkrkkaaabrakabrabaabrakabrabakaabrakabrabaarrbakkrkaabrakabrababrbakbkabrakabrabarraraabrakabrabakkabrakabrababbraabkkabrakabrabarbbakabrakabrabaabrakabrabarbabkabrakabrabarkrkabrakabrabakabrakabrababbabrakabrabaabrakabrabakrkabrakabrabakabrakabrabarrabrakabrabaabrakabrabaabbaaabrakabrabaabrakabrabaabrakabrabababrakabrabaabrakabrababkaabrakabrabarrbkarabrakabrababkakbrrrrabrakabrabakkbbrabrakabrabaabrakabrabaaabrakabrabaabrakabrabaabrakabrabaaaakrabrakabrabababrakabrabaabrakabrabarrraabrakabrabababrakabrababrrbrkrbkrbrkabrakabrabakabrakabrabaabrakabrabaraabrabrakabrabakabbkkkabrakabrabaabrakabrabakkbabrakabrabarakrrrrkbabaabrakabrababkabrakabrabaababrakabrabaraakbrarbakbabrabrakabrabaabrakabrabaabrakabrabakbkkkabrakabrabakrakbbarbkaaabrakabrabakbkbabrakabrababkbakrabrakabrabaabrakabrabarkbaakaarrkrbabrakabrabaaabrakabrabaabrakabrabaabrakabrabaabrakabrabaabrakabrabababrakabrabaabrakabrabaabrakabrabaabrakabrabaabrakabrabaabrakabrabaabrakabrabarrbaakbkkkrkarbabrakabrabakabrakabrababkbrabrakabrabababababrakabrabaabrakabrabakabrakabrabaarbkbrrabakakaabrakabrababkrabrakabrababkabrakabrabaabrakabrababbba";
    char pat[] = "abrakabraba";
    int q = 101; //liczba pierwsza

    search(pat, txt); //silowo
//    searchKMP(pat, txt);//kmp
//    searchRK(pat, txt, q);
//    searchBM(txt, pat);

    return 0;
}