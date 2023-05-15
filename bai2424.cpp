#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Nhapmang(int a[][20], int &h, int &c, int demh[])
{
    cout << "\n NHAP MANG: \n";
    int i, j;
    cout << "Nhap so hang: ";
    cin >> h;
    cout << "Nhap so cot: ";
    cin >> c;
    for (i = 0; i < h; i++)
    {
        demh[i] = 0;
        for (j = 0; j < c; j++)
        {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
            demh[i]++;
            if (a[i][j] == 0)
            {
                demh[i]--;
                break;
            }
        }
    }
    cout << "\n";
}

void Inmang(int a[][20], int h, int c)
{
    cout << "\n MANG: \n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == 0)
                break;
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << "\n";
}

void Tbhang(int a[][20], int h, int c)
{
    for (int i = 0; i < h; i++)
    {
        double total = 0;
        int count = 0;
        for (int j = 0; j < c && a[i][j] != 0; j++)
        {
            total += a[i][j];
            count++;
        }
        if (count > 0)
        {
            double average = total / count;
            cout << "\nTBC " << i + 1 << " la: " << average << endl;
        }
    }
}

void ThemPTu(int a[][20], int h, int c, int demh[])
{
    int i, j, k;
    cout << "\n \n";
    cout << "\n Them Phan Tu \n";
    do
    {
        cout << "\n Nhap hang k: ";
        cin >> k;
    } while (k < 0 || k >= h || demh[k] > c - 1);
    cout << "\n Nhap x muon them: ";
    cin >> a[k][demh[k]];
    a[k][demh[k] + 1] = 0;
    demh[k]++;
    cout << "\n MANG DA THEM: \n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == 0)
                break;
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void Sxhang(int a[][20], int h, int c)
{
    cout << "\n\n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = j + 1; k < c; k++)
            {
                if (a[i][j] == 0 || a[i][k] == 0)
                    break;
                if (a[i][j] < a[i][k])
                    swap(a[i][j], a[i][k]);
            }
        }
    }
    cout << "\n SX HANG THANH CONG \n";
    Inmang(a, h, c);
}

void Lamday(int a[][20], int h, int c, int demh[])
{
    cout << "\n\n";

    for (int i = 0; i < h; i++)
        for (int j = i + 1; j < h; j++)
        {
            if (demh[i] < demh[j])
            {
                for (int k = demh[j]; k > demh[i]; k++)
                    a[j][k] = a[i][k];
            }
        }
    cout << "\n HANG DA LAM DAY \n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int demh[20];
    int a[20][20], h, c;
    Nhapmang(a, h, c, demh);
    Inmang(a, h, c);
    Tbhang(a, h, c);
    ThemPTu(a, h, c, demh);
    Sxhang(a, h, c);
    Lamday(a, h, c, demh);
    cout << endl;
}