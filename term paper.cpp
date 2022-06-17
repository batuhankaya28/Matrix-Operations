/*=============================================================================================================================================
        
        BU ODEVDE DINAMIK BIR MATRIS DIZISINI TEMPLATE ILE OLUSTURUP BIR TAKIM ISLEMLERE TABI TUTTUK
        
        
===============================================================================================================================================*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iomanip>
#include<cmath>
#include <windows.h>

using namespace std;
//==============================================================================================================================================
//==============================================================================================================================================
//========================================================ODEV 3.KISIM TABLO ISLEMLERI==========================================================
//==============================================================================================================================================
//==============================================================================================================================================

template <class T>
class Table
{
    public:

    Table(); // Default 10x10 0 value table


    Table(const int, const int, const int); // RXC BOYUTLU VERILEN PARAMETRE DEGERLI TABLO


    Table(const int,const int ,const char); //RXC BOYUTLU RASTGELE TABLO


    int itemAt(const int ,const int ); // GIRILEN SATIR SUTUNU DONDUREN FONKSIYON


    void print(); // TABLOYU EKRANA YAZAN FONKSIYON


    int itemAt(string); // VERILEN STRING INDISINI GERI DONDUREN FONKSIYON


    int itemAt(string,string); // 2 PARAMETRELI STRING INDISINI GERI DONDUREN FONKSIYON


    private:
        int row,col,deger;
        string hrow[27];
        string hcol[27];
        string st;
        T **table = new T*[row];
};

//===================================================================================================================================================
//===================================================================================================================================================
//=================================================== ODEV 1.KISIM MATRIX ISLEMLERI==================================================================
//===================================================================================================================================================
//===================================================================================================================================================

template <class Tip>
class Matrix
 {

  public:

     Matrix(); // MATRISE PARAMETRE VERILMEDIGI ZAMAN

     Matrix(const int , const int , const int ); // MATRISE 3.PARAMETRE INT VERILDIGI ZAMAN

     Matrix(const int , const int , const char); // MATRISE 3.PARAMETRE CHAR VERILDIGI ZAMAN

     void print(); // MATRISI EKRANA YAZAR

	 void print(string); // MATRISI DOSYAYA YAZAR

     void resize(int , int); // MATRISI YENIDEN BOYUTLANDIRAN FONKSIYON

     void emul(Matrix); // ELEMAN DUZEYINDE CARPMA FONKSIYONU

     void T(); // MATRISIN TRANSPOZUNU ALAN FONKSIYON

     void det(); // MATRISIN DETERMINANTINI HESAPLAYAN FONKSIYON

     void inv(); // MATRISIN TERSINI ALAN FONKSIYON


    Tip &operator ()(int i, int j){
      return matrix[i][j];
    }


    Matrix operator+(const Matrix& m4)// + operator  Overloading
	{
		Matrix m6(satir,sutun,0);
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				m6.matrix[i][j] = this->matrix[i][j] + m4.matrix[i][j];
			}
		}
    return m6;

	}


	 Matrix operator-(const Matrix& m4)// - operator Overloading
	{
		Matrix m6(satir,sutun,0);
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				m6.matrix[i][j] = this->matrix[i][j] - m4.matrix[i][j];
			}
		}

		return m6;

	}


	 Matrix operator*(const Matrix& m4)// * operator  Overloading
	{
		Matrix m6(satir,m4.sutun,0);
		for (int i = 0; i < this->satir; i++)
		{
			for (int j = 0; j < m4.sutun; j++)
			{
                    for(int k = 0; k < m4.sutun ; k++)
                    {
                    m6.matrix[i][j] = m6.matrix[i][j] + (this->matrix[i][k] * m4.matrix[k][j]);
                   }

			}
		}

		return m6;

	}


    Matrix operator+(int deger) // MATRIS VE INTEGER BIR SAYININ TOPLANMA OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = this->matrix[i][j] + deger;
            }
        }
        return m6;
    }


    Matrix operator-(int deger) // MATRIS - SAYI OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = this->matrix[i][j] - deger;
            }
        }
        return m6;
    }


     Matrix operator*(int deger) // MATRIS * SAYI OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = this->matrix[i][j] * deger;
            }
        }
        return m6;
    }


     Matrix operator/(int deger) // MATRIS / INTEGER OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = this->matrix[i][j] / deger;
            }
        }
        return m6;
    }


    Matrix operator%(int deger) // MATRIS % INTEGER OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = this->matrix[i][j] % deger;
            }
        }
        return m6;
    }


    Matrix operator^(int deger) // MATRIS US ALMA OPERATOR OVERLOADINGI
    {
        Matrix m6(satir,sutun,0);
        for(int i=0; i < satir; i++)
        {
            for(int j = 0; j<sutun; j++)
            {
                m6.matrix[i][j] = pow(this->matrix[i][j],deger);
            }
        }
        return m6;
    }


  private:

    int satir = 0;
    int MatrisDegeri;
    int sutun = 0;
    Tip **matrix = new Tip*[satir];
};

//================================================================================================================================================
//============================================3.KISIM FONKSIYONLARIN TANIMLANDIGI KISIM===========================================================
//================================================================================================================================================

template <class T>
Table <T>::Table()
{
        this->row = 10;
		this->col = 10;
		this->deger = 0;
		table = new T*[row];
		int i;
		for(i=0; i<row; i++)
        {
            table[i] = new T[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
            table[i][j] =0;
            }
        }

         for(int i= 0; i<col; i++)
         {
            hcol[i] = 'A'+i;
         }

         for(int i=0; i<row; i++)
         {
             hrow[i] = '0'+i;
         }
}


template <class T>
Table<T>::Table(const int _r,const int _c,const int _d)
{
        row = _r;
		col = _c;
		deger = _d;
		table = new T*[row];
		int i;
		for(i=0; i<row; i++)
        {
            table[i] = new T[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
            table[i][j] = deger;
            }
        }

         for(int i= 0; i<col; i++)
         {
            hcol[i] = 'A'+i;
         }

         for(int i=0; i<row; i++)
         {
             hrow[i] = '0'+i;
         }
}


template <class T>
Table<T>::Table(const int _r,const int _c,const char _ch)
{
    if(_ch == 'r')
    {
        row =_r;
        col = _c;
        table = new T*[row];
        int i;
        //srand(time(NULL));
        for(i=0; i<row; i++)
        {
            table[i] = new T[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
            table[i][j] = rand()%255;
            }
        }

         for(int i= 0; i<col; i++)
         {
            hcol[i] = 'A'+i;
         }

         for(int i=0; i<row; i++)
         {
             hrow[i] = '0'+i;
         }
    }
    else
    {
        cout<<"Böyle bir deger yok!";
    }

}


template<class T>
int Table<T>::itemAt(const int _r ,const int _c)
{
    cout<<endl<<hrow[_r]<<".satir "<<hcol[_c]<<" sutunu return edildi ==> "<<table[_r][_c];
    return table[_r][_c];
}


template <class T>
void Table<T>::print()
{
        for(int i=0; i<col; i++)
        {
            cout<<"\t"<<hcol[i];
        }
        cout<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(j<1)
                {
                    cout<<hrow[i]<<"\t";
                }

                cout<<table[i][j]<<"\t";
            }
           cout<<endl;
        }
}


template <class T>
int Table<T>::itemAt(string s)
{
    int rtut,ctut;
    string tut = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string deger = "0123456789101112131415161718192021";

    for(int i = 0; i<col; i++)
    {
        if(tut[i] == s[0])
        {
            ctut = i;
        }
    }
    for(int k = 0; k<row; k++)
    {
        if(deger[k] == s[1])
        {
            rtut = k;
        }
    }

    cout<<endl<<hcol[ctut]<<hrow[rtut]<<" INDISI RETURN EDILDI."<<endl;
    return table[rtut][ctut];
}


template <class T>
int Table<T>::itemAt(string rs,string cs)
{
    int rtut,ctut;
    string tut = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string deger = "0123456789101112131415161718192021";

    for(int i = 0; i<row; i++)
    {
        if(deger[i] == rs[0])
        {
            ctut = i;
        }
    }
    for(int k = 0; k<col; k++)
    {
        if(tut[k] == cs[0])
        {
            rtut = k;
        }
    }

    cout<<endl<<hrow[rtut]<<hcol[ctut]<<" INDISI RETURN EDILDI."<<endl;
    return table[rtut][ctut];
}

//================================================================================================================================================
//================================================================================================================================================
//============================================= 1.KISIM FONKSIYON TANIMLARI ======================================================================
//================================================================================================================================================
//================================================================================================================================================

template<class Tip>
void Matrix<Tip>::det()
{
        Matrix* temp = new Matrix(satir,sutun,0);
        int det2 = 0;
        int det3 = 0;
        int kof1 = 0;
        int kof2 = 0;
        int kof3 = 0;
        if(satir == sutun && satir == 2 && sutun == 2)
        {
           det2 = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
           cout<<"Matris Determinant sonucu ==> "<<det2<<endl;
        }

         else if(satir == 3 && sutun == 3)
         {
           kof1 = matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]);
           kof2 = -1*matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]);
           kof3 = matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
           det3 = kof1+kof2+kof3;
           cout<<"Matrisin Determinant sonucu ==> "<<det3<<endl;
         }

}


template<class Tip>
void Matrix<Tip>::inv()
{

         Matrix br(satir,sutun,'e'); //BIRIM MATRIS OLUSTURMA KOMUTU
         float d,k;
         for(int i=0; i<satir; i++)
         {
          d = matrix[i][i];
             for(int j=0; j<sutun; j++)
             {
               this->matrix[i][j] = (float)this->matrix[i][j]/d; // MATRISIN BUTUN ELEMANLARINI KENDINE BOLUP 1 YAPMA
                 br.matrix[i][j] = (float)br.matrix[i][j]/d;
             }
         for(int x=0; x<sutun; x++)
         {
             if(x!=i){
                k = this->matrix[x][i];
                for(int j=0; j<sutun; j++){
                    this->matrix[x][j] = this->matrix[x][j] - (this->matrix[i][j]*k);
                    br.matrix[x][j] = br.matrix[x][j] - (br.matrix[i][j]*k);
                }
             }

         }
         }
        cout<<"MATRISIN TERSI ALINDI==>"<<endl;
        br.print();

}

template<class Tip>
void Matrix<Tip>::T()
{
    Matrix* temp = new Matrix(satir, sutun, 0);

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				temp->matrix[i][j] = this->matrix[j][i];

			}
		}

		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				this->matrix[i][j] = temp->matrix[i][j];
			}
		}
		cout << "Transpoze alindi" << endl;
}


template<class Tip>
void Matrix<Tip>::emul(Matrix m)
{
        Matrix emull(satir,sutun,0);
        if(m.satir == satir)
        {
            for(int i=0;i<satir;i++)
		    {
                for(int j=0;j<sutun;j++)
			    {
                emull.matrix[i][j] = this->matrix[i][j] * m.matrix[i][j];
			    }
            }
          cout<<endl;
          emull.print();
        }
        else
        {
            cout<<"Matris satir sutun esit degil!";
        }

}



template <class Tip>
Matrix<Tip>::Matrix()
{
		cout << "10x10 0 degerli matris olusturuldu" << endl;

		this->satir = 10;
		this->sutun = 10;
		this->MatrisDegeri = 0;
		matrix = new Tip*[satir];
        int i;
        for(i=0;i<satir;i++){
        matrix[i] = new Tip[sutun];
        }
            for(int i=0;i<satir;i++){
                for(int j=0;j<sutun;j++){
                    matrix[i][j] =0;
                    }
                }

}


template <class Tip>
Matrix<Tip>::Matrix(const int _a,const int _b,const int _MatrisDegeri)
{
      satir = _a;
      sutun = _b;
      MatrisDegeri = _MatrisDegeri;
      matrix = new Tip*[satir];
      int i;
      for(i=0;i<satir;i++){
        matrix[i] = new Tip[sutun];
      }
      for(int i=0;i<satir;i++){
        for(int j=0;j<sutun;j++){
          matrix[i][j] =_MatrisDegeri;
        }
      }
}


template <class Tip>
Matrix<Tip>::Matrix(const int _a,const int _b,const char _MatrisDegeri)
{
         if(_MatrisDegeri == 'e' )// BIRIM MATRIS URETME SARTI
         {
            satir = _a;
			sutun = _b;
			MatrisDegeri = 0;
            matrix = new Tip*[satir];
            int i;
            for(i=0;i<satir;i++){
            matrix[i] = new Tip[sutun];
            }
             for(int i=0;i<satir;i++){
               for(int j=0;j<sutun;j++){
                 matrix[i][j] =0;
                 if(i==j){
                  matrix[i][j] =1;
                         }
                     }
                }
           cout<<_a<<"x"<<_b<<"Birim Matris olusturuldu"<<endl<<endl;
         }

          else if(_MatrisDegeri == 'r') // RASTGELE MATRIS URETME SARTI
          {
              satir = _a;
              sutun = _b;
              MatrisDegeri = 0;
              matrix = new Tip*[satir];
              int i;
              //srand(time(NULL));
              for(i=0;i<satir;i++){
              matrix[i] = new Tip[sutun];
              }
               for(int i=0;i<satir;i++){
                for(int j=0;j<sutun;j++){
                 matrix[i][j] =rand()%255;
                }
            }
         }

         else
		{
			cout << "Kullanilamayan matris degeri!! ." << endl;
		}

}


template <class Tip>
void Matrix<Tip>::print()
{
      for(int i=0;i<satir;i++){
        for(int j=0;j<sutun;j++){
          cout<<matrix[i][j]<<" \t";
        }
        cout<<endl;
      }
}


template <class Tip>
void Matrix<Tip>::print(string dosyaAdi)
{
	    cout<<endl;
		ofstream dosya;
		dosya.open("file.txt");
		for (int i = 0; i < satir; i++)
		{
			for (int j = 0; j < sutun; j++)
			{
				dosya << matrix[i][j] << '\t';
			}
			dosya << endl;
		}


		dosya.close();

		cout << "Matris dosyaya yazildi." << endl;
}


template <class Tip>
void Matrix<Tip>::resize(int _satir,int _sutun)
{
        int tutr,tutc;
        tutr = satir;
        tutc = sutun;
		satir = _satir;
		sutun = _sutun;
		matrix = new Tip*[satir];
        int i;
        for(i=0;i<satir;i++)
        {
        matrix[i] = new Tip[sutun];
        }

        for(int i=0;i<satir;i++) // MATRÝSE YENÝ SATIR SUTUNLARA 0 KENDÝ SATIR SUTUNLARINA KENDÝ DEGERÝ ATANDIGI KISIM
        {
            for(int j=0;j<sutun;j++)
            {
            if(i<tutr && j<tutc)
            {
                matrix[i][j] =this->MatrisDegeri;
            }
            if(i>=tutr || j>=tutc)
            {
                matrix[i][j] = 0;
            }
            }
        }



		cout << "Matrisin boyutu degistirildi." << endl<<endl;
}



int main()
{
   //Matrix <int> *m1 = new Matrix<int>(4,4,3);
   //Matrix <int> *m2 = new Matrix<int>(4,4,2);
   //int a; // INTEGER GIRILDIGI ZAMAN KULLANILAN DEGISKEN
   //int s; //STRING GIRILDIGI ZAMAN KULLANILAN DEGISKEN
   cout<<fixed<<setprecision(2); // VIRGULDEN SONRAKI GOZUKECEK HANE SAYISI
   //Table<int>tb(7,6,4); //Table<int>(int r,int c,int d) Test
   //Table<int>tb(7,6,'r'); //Table<int>(int r,int c,char ch) Test
   //Table<int>tb;//Table<int>() TEST
   //tb.print(); //TABLOYU EKRANA YAZAR
   //a = tb.itemAt(4,4); // itemAt DEGER RETURN TEST
   //s = tb.itemAt("B3"); // itemAt TEK STRING TEST
   //s =tb.itemAt("2","C"); // itemAt 2 STRÝNG RETURN TEST
   //cout<<endl<<a; // itemAt DEGER TEST
   //cout<<endl<<s; // ÝTEMAT STRÝNG TEST
   //m2->print();
   //*m2 = (*m1)+(*m2);
   cout<<endl;
   //m2->print();
   cout<<endl;
   //m2->resize(3,6);
   //m2->T();
   //m1->det();
   //m1->print("file.txt");
   //*m1 = (*m1)+10;
   //*m1 = (*m1)-10;
   //m1->emul(*m2);
   //m1->inv();
    cout<<endl;
   //m2->print();
   return 0;
}
