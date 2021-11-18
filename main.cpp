#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <list>
#include <sstream>
#include <conio.h>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int PIN;
int git1=0;
int git2=0;
string dosyastr;
string duntarih;

class SeferNode
{
private:

    int Seferno;
    string Guzergah;
    string GTarih;
    string DTarih;
    int Kapasite;
    int sFiyat;
    string Gidis;
    string Donus;
    string Saat;
    string Plaka;
    string Kaptan;
    string Firma;

    string Selem;
    SeferNode *Sprev;
    SeferNode *Snext;
    friend class SeferLinkedList;
};

class SeferLinkedList
{
private:
    SeferNode *sHeader;
    SeferNode *sTrailer;

public:

    string gidis;
    string donus;
    double gSeferno;

    string guzergah;
    string gitarih;
    string dotarih;
    string gSeferSaat;
    int kapasite;
    int sFiyat;
    string sPlaka;
    string kaptan;
    string firma;

    int gSeferYear;
    int gSeferMonth;
    int gSeferDay;

    int dSeferYear;
    int dSeferMonth;
    int dSeferDay;

    int KayitYear;
    int KayitMonth;
    int KayitDay;

    SeferLinkedList(); //Constructer
    ~SeferLinkedList();
    bool empty() const; //bos mu?
    const string &front() const;
    const string &back() const;
    void sBasaEkle(const string &e);

    void sSonaEkle(const int &seferno,const string &guzergah,const string &gitarih,const string &gSeferSaat,const string &gidis,const string &donus,const int &kapasite,const int &sFiyat,
                                const string &Plaka,const string &kaptan,const string &firma);

    void sListeyeEkle(const string &x, const string &e);
    void sBastanSil();
    void sSondanSil();
    void sElemanSil(const string &e);
    void sListeyiListele();

protected:
    void sDugumEkle(SeferNode *y,const int &seferno,const string &guzergah,const string &gitarih,const string &gSeferSaat,const string &gidis,const string &donus,const int &kapasite,const int &sFiyat,
                                const string &Plaka,const string &kaptan,const string &firma); // y den öncesine 1 dü?üm ekler
    void sDugumSil(SeferNode *y);
    };


class KoltukNode
{
private:
    string Kelem;
    string MAd;
    string MSoyad;
    int MTC;
    string Durum;
    int seferno;
    int Fiyat;
    string Cinsiyet;

    KoltukNode *Kprev;
    KoltukNode *Knext;
    friend class KoltukLinkedList;
};


class KoltukLinkedList
{
private:

    KoltukNode *kHeader;
    KoltukNode *kTrailer;


public:
    string mAd;
    string mSoyad;
    int mTC;
    string durum;
    string cinsiyet;
    string koltukno;
    int sefer;
    int Fiyat;
    int kapasit;

    KoltukLinkedList(); //Constructer
    ~KoltukLinkedList();
    bool  empty() const; //boþ mu?
    const string &front() const;
    const string &back() const;
    void kBasaEkle(const string &e);
    void kSonaEkle(const int &sefer,const string &e,const int &fiyat,const int &kpst,const string &mAd,const string &mSoyad,const string &cinsiyeti,const string &durum);
    void kListeyeEkle(const string &x, const string &e);
    void kBastanSil();
    void kSondanSil();
    void kElemanSil(const string &e);
    void kListeyiListele(const int &kapasite,const int &sec);
    void kotobus(const int &kpst,const string &koltukNo,const string &durumm);
    void kdosyayaz(const int &sec,const int &sefer,const int &g1,const int &g2);

protected:
    void kDugumEkle(KoltukNode *y,const int &sefer,const string &e,const int &fiyat,const int &kpst,
                                  const string &mAd,const string &mSoyad,const string &cinsiyeti,const string &durum); // y den öncesine 1 dü?üm ekler
    void kDugumSil(KoltukNode *y);

};

SeferLinkedList::SeferLinkedList()
{
    sHeader=new SeferNode;
    sTrailer=new SeferNode;
    sHeader->Snext=sTrailer;
    sTrailer->Sprev=sHeader;
}

KoltukLinkedList::KoltukLinkedList()
{
    kHeader=new KoltukNode;
    kTrailer=new KoltukNode;
    kHeader->Knext=kTrailer;
    kTrailer->Kprev=kHeader;
}

SeferLinkedList::~SeferLinkedList()
{
    while(!empty())
    {
      sBastanSil();
      delete sHeader;
      delete sTrailer;
    }
}

KoltukLinkedList::~KoltukLinkedList()
{
    while(!empty())
    {
      kBastanSil();
      delete kHeader;
      delete kTrailer;
    }
}

bool SeferLinkedList::empty() const
{
    return (sHeader->Snext==sTrailer);
}

bool KoltukLinkedList::empty() const
{
    return (kHeader->Knext==kTrailer);
}

const string &SeferLinkedList::front() const //ba?taki elemany getirir
{
    return (sHeader->Snext->Selem);
}

const string &KoltukLinkedList::front() const //ba?taki elemany getirir
{
    return (kHeader->Knext->Kelem);
}

const string &SeferLinkedList::back() const //sondaki elemany getirir
{
    return (sTrailer->Sprev->Selem);
}

const string &KoltukLinkedList::back() const //sondaki elemany getirir
{
    return (kTrailer->Kprev->Kelem);
}

void SeferLinkedList::sDugumEkle(SeferNode *y,const int &seferno,const string &guzergah,const string &gitarih,const string &gSeferSaat,const string &gidis,const string &donus,const int &kapasite,const int &sFiyat,
                                const string &Plaka,const string &kaptan,const string &firma)
{
    SeferNode *u = new SeferNode;
    u->Seferno=seferno;
    u->Guzergah=guzergah;
    u->GTarih=gitarih;
    u->DTarih=dotarih;
    u->Saat=gSeferSaat;
    u->Gidis=gidis;
    u->Donus=donus;
    u->Kapasite=kapasite;
    u->sFiyat=sFiyat;
    u->Plaka=Plaka;
    u->Kaptan=kaptan;
    u->Firma=firma;

    u->Snext=y;
    u->Sprev=y->Sprev;
    y->Sprev->Snext=y->Sprev=u;

    PIN++;
}

void KoltukLinkedList::kDugumEkle(KoltukNode *y,const int &sefer,const string &e,const int &fiyat,const int &kpst,
                                  const string &mAd,const string &mSoyad,const string &cinsiyeti,const string &durum)
{
    KoltukNode *u = new KoltukNode;

    u->seferno=sefer;
    u->Kelem=e;
    u->Fiyat=fiyat;
    u->MAd=mAd;
    u->MSoyad=mSoyad;
    u->Cinsiyet=cinsiyeti;
    u->Durum=durum;


    u->Knext=y;
    u->Kprev=y->Kprev;
    y->Kprev->Knext=y->Kprev=u;

}


void SeferLinkedList::sSonaEkle(const int &seferno,const string &guzergah,const string &gitarih,const string &gSeferSaat,const string &gidis,const string &donus,const int &kapasite,const int &sFiyat,
                                const string &Plaka,const string &kaptan,const string &firma)
{
    sDugumEkle(sTrailer,seferno,guzergah,gitarih,gSeferSaat,gidis,donus,kapasite,sFiyat,Plaka,kaptan,firma);
}

void KoltukLinkedList::kSonaEkle(const int &sefer,const string &e,const int &fiyat,const int &kpst,const string &mAd,const string &mSoyad,
                                 const string &cinsiyeti,const string &durum)
{
    kDugumEkle(kTrailer,sefer,e,kpst,fiyat,mAd,mSoyad,cinsiyeti,durum);
}

/* void SeferLinkedList::sListeyeEkle(const string &e, const string &x)
{
    bool sEklendiMi=false;
    SeferNode *u=sHeader;

    do{
        u=u->Snext;
        if(u->Selem==x);
        {
            sDugumEkle(u,e);
            sEklendiMi=true;
        }
      }while (u!=sTrailer);
    cout<<"Önüne eklemek istediðiniz sefer numarasý bulunamamýþtýr !"<<endl;
}
*/
/*
void KoltukLinkedList::kListeyeEkle(const string &e, const string &x)
{
    bool kEklendiMi=false;
    KoltukNode *u=kHeader;

    do{
        u=u->Knext;
        if(u->Kelem==x);
        {
            kDugumEkle(u,e);
            kEklendiMi=true;
        }
      }while (u!=kTrailer);
    cout<<"Önüne eklemek istediðiniz koltuk numarasý bulunamamýþtýr !"<<endl;
}
*/
void SeferLinkedList::sDugumSil(SeferNode *y)
{
    SeferNode *u=y->Sprev;
    SeferNode *w=y->Snext;
    u->Snext=w;
    w->Sprev=u;
    delete y;
}

void KoltukLinkedList::kDugumSil(KoltukNode *y)
{
    KoltukNode *u=y->Kprev;
    KoltukNode *w=y->Knext;
    u->Knext=w;
    w->Kprev=u;
    delete y;
}

void SeferLinkedList::sBastanSil()
{
    sDugumSil(sHeader->Snext);
}

void KoltukLinkedList::kBastanSil()
{
    kDugumSil(kHeader->Knext);
}

void SeferLinkedList::sSondanSil()
{
    sDugumSil(sTrailer->Sprev);
}

void KoltukLinkedList::kSondanSil()
{
    kDugumSil(kTrailer->Kprev);
}

void SeferLinkedList::sElemanSil(const string &e)
{
    bool SilindiMi=false;
    SeferNode *u=sHeader;
    do{
        u=u->Snext;
        if(u->Selem==e)
        {
            sDugumSil(u);
            SilindiMi=true;
        }
    }while(u!=sTrailer);
    if(SilindiMi==false)
        cout<<"silmek istediðiniz sefer bulunamadý"<<endl;
}

void KoltukLinkedList::kElemanSil(const string &e)
{
    bool SilindiMi=false;
    KoltukNode *u=kHeader;
    do{
        u=u->Knext;
        if(u->Kelem==e)
        {
            kDugumSil(u);
            SilindiMi=true;
        }
    }while(u!=kTrailer);
    cout<<"Silme islemi basarili"<<endl;
    if(SilindiMi==false)
        cout<<"silmek istediðiniz koltuk bulunamadý"<<endl;
}

void SeferLinkedList::sListeyiListele()
{
    if (SeferLinkedList::empty())
    {
        cout<<"Sefer listesi bos"<<endl;
        return;
    }
    else
    {
        SeferNode *u=sHeader->Snext;
        cout<<"--------------------Sefer Tablosu--------------------"<<endl<<endl;
        do{

            cout<<" Sefer ID ";
            cout<<"-> ";
            cout<<u->Seferno<<" ";

            cout<<"Guzergah";
            cout<<"-> ";
            cout<<u->Guzergah<<" ";

            cout<<"G.Tarihi ";
            cout<<"-> ";
            cout<<u->GTarih<<" ";

            cout<<"D.Tarihi ";
            cout<<"-> ";
            cout<<u->DTarih<<" ";

            cout<<"Saat ";
            cout<<"-> ";
            cout<<u->Saat<<" ";

            cout<<"Gidis ";
            cout<<"-> ";
            cout<<u->Gidis<<" ";

            cout<<"Donus ";
            cout<<"-> ";
            cout<<u->Donus<<" ";

            cout<<"Kapasite ";
            cout<<"-> ";
            cout<<u->Kapasite<<" ";

            cout<<"Fiyat ";
            cout<<"-> ";
            cout<<u->sFiyat<<" ";

            cout<<"Plaka ";
            cout<<"-> ";
            cout<<u->Plaka<<" ";

            cout<<"Kaptan ";
            cout<<"-> ";
            cout<<u->Kaptan<<" ";

            cout<<"Firma ";
            cout<<"-> ";
            cout<<u->Firma<<endl<<endl;

            cout<<endl<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl<<endl;

            u=u->Snext;
        }while(u!=sTrailer);
    }
}

void gitbul(int sayac,bool sec)
{
     string gsatir="";
    string satir ="";
    int strsyc=0;
    int gecici1;
    int gecici2;
    int klmsyc;
    string dosdos=dosyastr;

    if(sec==true)
    {
       dosdos=duntarih;
    }

    ifstream gdosya(dosdos.c_str());
    int saay=1;

    while ( getline(gdosya, gsatir) )
    {
        char strdz[gsatir.size()+1];
        strcpy(strdz,gsatir.c_str());
        klmsyc=0;

        char *kelime = strtok(strdz, " ");
        while (kelime != NULL)
        {
          string karsilastir=kelime;
          if(karsilastir=="Seferno")
          {
            if(saay<=sayac)
            {
                git1=strsyc;
                saay++;
            }
          }
            kelime = strtok(NULL," ");
            klmsyc++;


         }
         strsyc++;
    }

    gsatir="";
    strsyc=0;
    ifstream ggdosya(duntarih.c_str());
    saay=1;
    while ( getline(ggdosya, gsatir) )
    {
        char strdz[gsatir.size()+1];
        strcpy(strdz,gsatir.c_str());
        klmsyc=0;

        char *kelime = strtok(strdz, " ");
        while (kelime != NULL)
        {
          string karsilastir=kelime;

          if(karsilastir=="----")
          {
              if(saay<=sayac)
            {
                git2=strsyc;
                saay++;
            }

          }
            kelime = strtok(NULL," ");
            klmsyc++;

         }
         strsyc++;
    }

    gdosya.close();
    ggdosya.close();
}

void KoltukLinkedList::kdosyayaz(const int &sec,const int &sefer,const int &g1,const int &g2)
{
    if(sec==0)
    {
        string dosdos=dosyastr;
        if(g1==5 && g2==5)
        {
            dosdos=duntarih;
        }
        ifstream dosyaa(dosdos.c_str());
        string satir ="";
        int toplamsatir=0;
        string harf [11] = {"A","B","C","D","E","F","G","H","I","J","K"};
        int kapasite [100];
        string karsilastir;
        int heleman [100];
        int say=0;
        int klmsyc;
        gitbul(1,false);

        int strsyc=0;

        while ( getline(dosyaa,satir) )
        {
            char strdz[satir.size()+1];
            strcpy(strdz,satir.c_str());
            klmsyc=0;

            char *kelime = strtok(strdz, " ");

            while (kelime != NULL)
            {
                karsilastir=kelime;
                if(strsyc>0 && klmsyc==6 && strsyc<git1)
                {
                    kapasite[say]=stoi(karsilastir);
                    heleman[say]=kapasite[say]/4;
                    say++;
                }
                kelime = strtok(NULL," ");
                klmsyc++;
            }
            strsyc++;
        }
        dosyaa.close();

      ofstream  write(dosyastr.c_str(), ios::app);

      string koltuk;

      for(int s=0;s<say;s++)
      {
          write<<"Seferno : "<<s+1<<" Doluluk Tablosu"<<endl;

         for(int i=0;i<heleman[s];i++)
            {
                for(int j=1;j<5;j++)
                {
                    koltuk=harf[i]+to_string(j);


                    write<<koltuk;
                    write<< " -> ";
                    write<<"b";
                    write<<"    ";

                    if(j%4==0)
                    {
                        write<<endl;
                    }
                    if(j%2==0 && j%4!=0)
                    {
                        write<<"              ";
                    }


                }
        }

          write<<"----"<<endl;
    }

    }

    if(sec==1)
    {
        ifstream dosyaa(dosyastr.c_str());
        string satir ="";
        int strsyc=0;
        int klmsyc;

        ofstream write("gecici2.txt");

        while ( getline(dosyaa, satir) )
        {
            if(strsyc==git1)
            {
                write<<"Seferno : "<<sefer<<" Doluluk Tablosu"<<endl;
            }
            if(strsyc<git1)
            {
                write<<satir<<endl;
            }
            strsyc++;
        }
        dosyaa.close();
    int kosyc=1;
    KoltukNode *u=kHeader->Knext;


        do{
        if(u->seferno==sefer)
       {

        write<<u->Kelem<<" -> "<<u->Durum;
     //   cout<<"u->Kelem : "<<u->Kelem<<" -> "<<"u->Durum : "<<u->Durum<<endl;

        if(kosyc%4==1 || kosyc%4==3)
        {
            write<<"    ";
        }
        if(kosyc%4==2)
        {
            write<<"                  ";
        }

        if(kosyc%4==0)
        {
            write<<endl;
        }

        }
        kosyc++;
        u=u->Knext;

        }while(u!=kTrailer);

        ifstream dosyak(dosyastr.c_str());
        strsyc=0;
        satir="";

        while ( getline(dosyak, satir) )
        {
            if(strsyc>=git2)
            {
                write<<satir<<endl;
            }
            strsyc++;
        }
        dosyak.close();
    }
}

void KoltukLinkedList::kListeyiListele(const int &kapasite,const int &sec)
{
    cout<<"           ------------------------------Koltuk Tablosu---------------------------"<<endl<<endl;

        KoltukNode *u=kHeader->Knext;

       if(sec==0)
     {
         int sayac=0;
         bool eklendi=false;
         string karsilastir;
         int oldu=1;
         bool yazdi=false;
         bool gbul=true;
         gitbul(1,false);
         gbul=false;

        do
        {
            ifstream okudosya(dosyastr.c_str());

            string okusatir="";
            int strsyc=0;
            int klmsyc;
            while ( getline(okudosya, okusatir) )
            {
              char strdz[okusatir.size()+1];
              strcpy(strdz,okusatir.c_str());
              klmsyc=0;
              char *kelime = strtok(strdz, " ");
            while (kelime != NULL)
            {

              karsilastir=kelime;;
              if(git1>0 && git2>0 && strsyc>=git1 && strsyc<git2)
              {
                 if(eklendi==false && strsyc==git1 && klmsyc==2 )
                 {
                    if(karsilastir==to_string(kapasite))
                     {
                        eklendi=true;
                     }
                 }
                   if(eklendi==true && oldu%12==1)
                     {
                         if(yazdi==false)
                         {

                            cout<<"                 bos --> b        dolu --> d        rezerve --> r"<<endl<<endl;
                            cout<<"               --------------------------------------------------------"<<endl;
                            cout<<"              |                                                        |"<<endl;
                     //       cout<<"              | ";
                            yazdi=true;
                         }
                         cout<<"              | ";
                        cout<<okusatir;
                        cout<<" |"<<endl;
                     }
                oldu++;
              }
              kelime = strtok(NULL," ");
              klmsyc++;
            }
            strsyc++;
        }
        sayac++;
         if(eklendi==false)
        {
           gitbul(kapasite,false);
           sayac++;
        }
         okudosya.close();

        }while(eklendi==false);
        cout<<"               --------------------------------------------------------"<<endl;

     }
     if(sec==1)
     {
         int i;
        int j;
        string koltuk;
        int heleman=kapasite/4;

        string harf [11] = {"A","B","C","D","E","F","G","H","I","J","K"};


        cout<<"                 bos --> b        dolu --> d        rezerve --> r"<<endl<<endl;
        cout<<"               -----------------------------------------------------------"<<endl;
        cout<<"              |                                                           |"<<endl;
        cout<<"              | ";

        for(int i=0;i<heleman;i++)
        {
            for(j=1;j<5;j++)
            {
                koltuk=harf[i]+to_string(j);

                if(j==1 && i!=0)
                {
                    cout<<"              | ";
                }
                cout<<koltuk;
                cout << " -> ";
                cout<<"b";
                cout<<"    ";

                if(j%4==0)
                {
                    cout<<"|";
                    cout<<endl;
                }
                if(j%2==0 && j%4!=0)
                {
                    cout<<"              ";
                }


            }
        }
        cout<<"               -----------------------------------------------------------"<<endl;
     }

    if(sec==2)
    {
        cout<<endl<<endl;
        cout<<"Sefer No ";
        cout<<"-> ";
        cout<<u->seferno<<endl;
        do{
        cout<<"Koltuk No ";
        cout<<"-> ";
        cout<<u->Kelem<<" ";


        cout<<"Ad ";
        cout<<"-> ";
        cout<<u->MAd<<" "<<u->MSoyad<<" ";

        cout<<"Cinsiyet ";
        cout<<"-> ";
        cout<<u->Cinsiyet<<" ";

        cout<<"Durum ";
        cout<<"-> ";
        cout<<u->Durum<<" "<<endl;

           u=u->Knext;
        }while(u!=kTrailer);
        cout<<"-----------------------------------------------------------------------"<<endl<<endl;
    }




}

int main()
{
    system("color 4F");
    cout<<endl;
    cout<<"                                             ***   SEYR-U SEFER  ***"<<endl<<endl;
    cout<<"                                                   HOSGELDINIZ"<<endl<<endl;

    int i=0;
    int sayi=1;
    string grup;
    int kisisayisi;
    int j=0;
    bool hata=false;
    int basamak=1;
    int tgecici;
    string gc;
    string aynigc;
    string kptn,kp1,kp2;
    string kol;

    bool birg;
    bool bird;
    bool ayni;
    bool ayni2=false;
    int srsyc=0;
    int silsayac=1;

    int dgecici;
    int sefersayac=0;
    int satirsayi=0;
    int klmsyc;
    int strsyc;
    string plk,p1,p2,p3;

    int Seferno;
    int sef;
    bool sefhata=false;
    bool gbul=true;
    gitbul(1,false);
    int seft;

    string Koltukno,MAd,MSoyad,MTC;
    SeferLinkedList s;
    KoltukLinkedList k;

    string harf [11] = {"A","B","C","D","E","F","G","H","I","J","K"};
    int islemno;
        ////////////  Gun bulma ///////////////////////////////
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];
        string dossa;

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,80,"%d.%m.%Y",timeinfo);
        string strnn(buffer);
        dossa=strnn+".txt";
        char dosyastrng[dossa.size() + 1];
        strcpy(dosyastrng, dossa.c_str());
        int m;
        dosyastr = "";
        int a_size = sizeof(dosyastrng) / sizeof(char);
        for (m = 0; m<a_size; m++)
        {
            dosyastr = dosyastr + dosyastrng[m];
        }
    ///////////////////////////////////////////////////////////

    string gsatir="";
    string satir ="";
    strsyc=0;
    bool ilk=true;
    ifstream gdosya(dosyastr.c_str());
    while ( getline(gdosya, gsatir) )
    {
        char strdz[gsatir.size()+1];
        strcpy(strdz,gsatir.c_str());
        klmsyc=0;

        char *kelime = strtok(strdz, " ");
        while (kelime != NULL)
        {
          string karsilastir=kelime;
          if(karsilastir=="Seferno" && ilk==true)
          {
            git1=strsyc;
            ilk=false;
          }
          if(karsilastir=="*")
          {
             git2=strsyc;
          }
            kelime = strtok(NULL," ");
            klmsyc++;
         }
         strsyc++;
         satirsayi++;
    }
    gdosya.close();

    ////////////dunun tarihi///////////////
        time_t rtime;
        struct tm * tinfo;
        char bufffer[80];
        char gun[10];

        string dossat;

        time (&rtime);
        tinfo = localtime(&rtime);

        strftime(bufffer,80,".%m.%Y",tinfo);
        strftime(gun,10,"%d",tinfo);
        string gunuacikla(gun);
        int dun=stoi(gunuacikla)-1;
        string strn(bufffer);
        dossat=strn+".txt";
        duntarih=to_string(dun)+strn+".txt";

    ///////////////////////////////////////

do
{
    cout<<endl<<"*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *"<<endl;
    cout<<"  Yapmak istediginiz islem numarasini giriniz."<<endl<<endl;

    cout<<"   1- Bilet Satis Islemleri"<<endl;
    cout<<"   2- Seferleri Listele"<<endl;
    cout<<"   3- Sefer Ekle"<<endl;
    cout<<"   4- Sefer Sil"<<endl;
    cout<<"   5- Kaptan Degistir"<<endl;
    cout<<"   6- Sefer Gelir Hesapla"<<endl;
    cout<<"   7- Satis Iptali"<<endl;
    cout<<"   8- Yeni Gun"<<endl;
    cout<<"   9- Cikis"<<endl<<endl<<endl;

    cout<<" Islem No Giriniz : ";
    cin>>islemno;
    cout<<endl;

    if (islemno==1)
    {
        cout<<"             -------------------------  Bilet Satis Islemleri  -----------------------              "<<endl<<endl;
        cout<<"  NOT: Su an icin Kocaeli - Ankara,  Kocaeli - Istanbul,  Kocaeli - Izmir seferlerimiz bulunmaktadir."<<endl<<endl;

        ifstream dosyaa(dosyastr.c_str());
        ifstream gdosya(dosyastr.c_str());
        string ad,soyad,cins;

          string gsatir="";
          string satir ="";
          strsyc=0;
          gitbul(1,false);

            while ( getline(gdosya, gsatir) )
            {
                if(strsyc<git1)
                {
                    cout<<gsatir<<endl;
                }
                strsyc++;
            }
                gdosya.close();

            cout<<endl<<endl;
            cout<<" Sefer numarasi seciniz : ";
            cin>>k.sefer;
            string seff=to_string(k.sefer);
            cout<<endl;
            strsyc=0;

            while ( getline(dosyaa, satir) )
            {
              char strdz[satir.size()+1];
              strcpy(strdz,satir.c_str());
              klmsyc=0;
              char *kelime = strtok(strdz, " ");
              while (kelime != NULL)
              {
                  if(strsyc<git1)
                {//cout<<"git2: "<<git2<<endl;
                  if(strsyc>0 && klmsyc==0)
                    {
                        gc=kelime;
                        seft=stoi(kelime);
                    }

                  if(klmsyc==0 && k.sefer==seft)
                    {
                        sefhata=true;
                    }
                }
                kelime = strtok(NULL," ");
                klmsyc++;
              }
                strsyc++;
                satirsayi++;
            }
            dosyaa.close();

             if(sefhata==true)
            {
                cout<<" Cinsiyet giriniz (k/e) : ";
                cin>>k.cinsiyet;
                cins=k.cinsiyet;

                if(k.cinsiyet!="k" && k.cinsiyet!="e")
                {
                   cout<<endl;
                   cout<<" Cinsiyeti yanlis girdiniz."<<endl<<endl;
                   hata=true;
                }
                if(hata==false)
                {
                    cout<<" Ad giriniz    : ";
                    cin>>k.mAd;
                    ad=k.mAd;

                    size_t found = k.mAd.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

                    if (found!=string::npos)
                    {
                        cout<<endl;
                        cout<<" Turkce karakter girdiniz."<<endl<<endl;

                    }

                    cout<<" Soyad giriniz : ";
                    cin>>k.mSoyad;
                    soyad=k.mSoyad;

                    size_t found2 = k.mSoyad.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

                    if (found2!=string::npos)
                    {
                        cout<<endl;
                        cout<<" Yanlis karakter girdiniz."<<endl<<endl;
                    }

                    ifstream dosya2(dosyastr.c_str());

                    satir ="";
                    strsyc=0;
                    while ( getline(dosya2, satir) )
                    {
                      char strdz[satir.size()+1];
                      strcpy(strdz,satir.c_str());
                      klmsyc=0;
                      char *kelime = strtok(strdz, " ");
                      while (kelime != NULL)
                      {
                        if(strsyc<git1 || strsyc>git2)
                        {
                            if(k.sefer==strsyc && klmsyc==7)
                            {
                                k.Fiyat=stoi(kelime);
                            }

                            if(k.sefer==strsyc && klmsyc==6)
                            {
                                k.kapasit=stoi(kelime);
                            }
                        }
                        kelime = strtok(NULL," ");
                        klmsyc++;
                      }
                       strsyc++;
                       satirsayi++;
                    }
                    dosya2.close();
                    cout<<endl;

                    k.kListeyiListele(stoi(seff),0);
                    string koltuk;
                    cout<<endl<<" Koltuk numarasini girin (orn; A3) : ";
                    cin.clear();
                    cin.ignore(1);
                    cin>>koltuk;
                    cout<<endl;

                    int hrf=k.kapasit/4;
                    bool kntrl=false;
                    for(int i=0;i<hrf;i++)
                    {
                        for(int j=1;j<5;j++)
                        {
                            kol=harf[i]+to_string(j);
                            if(koltuk==kol)
                            {
                                kntrl=true;
                            }
                        }
                    }

                    if(kntrl==false)
                    {
                        cout<<"Yanlis koltuk numarasi girdiniz."<<endl;
                    }
                    else
                    {
                        string durum;
                        cout<<" Koltugu rezerve mi etmek istersiniz, satin mi almak istersiniz? (rezerve -> r / satin alma -> d) : ";
                        cin>>durum;
                        if(durum!="r" && durum!="d")
                        {
                            cout<<" Yanlis giris yaptiniz. "<<endl;
                            hata=true;
                        }
                        else
                        {
                            bool eklendi=false;

                               int sat=0;

                                    string karsilastir;
                                    int oldu;
                                    string k1,k2;
                                    int kapasite;
                                    int klmsyc;
                                    int farkli;
                                    bool gg=true;
                                    bool aynisi=false;
                                    int sayac=1;
                                    gitbul(1,false);
                                    bool degistir=false;
                                    cout<<endl;
                                    int stut,ktut;
                                    bool gec=false;
                                    ofstream write("gecici2.txt",ios::app);
                                    int st;
                                    int fi,kap;

                                  do
                                {
                                    oldu=1;
                                    ifstream dosyaa(dosyastr.c_str());
                                    string ksatir="";
                                    strsyc=0;
                                    while ( getline(dosyaa, ksatir) )
                                    {
                                        char strdz[ksatir.size()+1];
                                        strcpy(strdz,ksatir.c_str());
                                        klmsyc=0;
                                        char *kelime = strtok(strdz, " ");
                                        while (kelime != NULL)
                                        {
                                          karsilastir =kelime;
                                          if(strsyc<git1)
                                          {
                                              write<<ksatir<<endl;
                                              if(strsyc>0)
                                              {
                                                  if(karsilastir==seff)
                                                  {
                                                    st=strsyc;
                                                    eklendi=true;
                                                  }
                                                   if(strsyc==st && klmsyc==6)
                                                   {
                                                       kap=stoi(karsilastir);
                                                   }
                                                   if(strsyc==st && klmsyc==7)
                                                   {
                                                       fi=stoi(karsilastir);
                                                   }
                                              }
                                          }

                                          if(git1>0 && git2>0 && strsyc>=git1 && strsyc<git2)
                                          {

                                              if(eklendi==false && strsyc==git1 && klmsyc==2 )
                                              {

                                                  if(karsilastir==seff)
                                                  {
                                                    k.sefer=stoi(karsilastir);
                                                    eklendi=true;
                                                  }
                                              }

                                              if(eklendi==true && strsyc>git1 && (klmsyc==0 || klmsyc==3 || klmsyc==6 || klmsyc==9 ) )
                                              {
                                                  if(karsilastir==koltuk)
                                                  {
                                                      k.koltukno=karsilastir;
                                                      degistir=true;
                                                      ktut=klmsyc;
                                                      stut=strsyc;
                                                  }
                                                  else
                                                  {
                                                      k.koltukno=karsilastir;
                                                  }
                                                  if(k.koltukno=="A1")
                                                  {
                                                      gec=true;
                                                  }
                                                  else
                                                  {
                                                    gec=false;
                                                  }
                                              }

                                              if(eklendi==true && strsyc>git1 && (klmsyc==2 || klmsyc==5 || klmsyc==8 || klmsyc==11 ))
                                              {
                                                  if(karsilastir=="b" && strsyc==stut && klmsyc==ktut+2)
                                                  {
                                                      k.durum=durum;
                                                  }
                                                  if(strsyc!=stut || (strsyc==stut && klmsyc!=ktut+2))
                                                  {
                                                      k.durum=karsilastir;
                                                  }
                                                  if(k.durum=="b" && (strsyc!=stut ||(strsyc==stut && klmsyc!=ktut+2)))
                                                  {
                                                      k.kapasit=0;
                                                      k.Fiyat=0;
                                                      k.mAd="yok";
                                                      k.mSoyad="yok";
                                                      k.cinsiyet="yok";
                                                  }
                                                  aynisi=true;
                                              }
                                         if((gec==false && eklendi==true && aynisi==true && oldu%3==2))
                                      {
                                            //cout<<k.sefer<<" "<<k.koltukno<<" "<<k.kapasit<<" "<<k.Fiyat<<" "<<k.mAd<<" "<<k.mSoyad<<" "<<k.cinsiyet<<" "<<k.durum<<" oldu : "<<oldu<<endl;
                                            k.kSonaEkle(k.sefer,k.koltukno,k.kapasit,k.Fiyat,k.mAd,k.mSoyad,k.cinsiyet,k.durum);
                                      }
                                        else if(gec==true && aynisi==true && eklendi==true)
                                      {
                                          //cout<<k.sefer<<" "<<k.koltukno<<" "<<k.kapasit<<" "<<k.Fiyat<<" "<<k.mAd<<" "<<k.mSoyad<<" "<<k.cinsiyet<<" "<<k.durum<<endl;
                                          k.kSonaEkle(k.sefer,k.koltukno,k.kapasit,k.Fiyat,k.mAd,k.mSoyad,k.cinsiyet,k.durum);
                                      }
                                            oldu++;
                                          }
                                          kelime = strtok(NULL," ");
                                          klmsyc++;
                                        }
                                        strsyc++;
                                    }
                                    if(eklendi==false)
                                    {
                                        gitbul(stoi(seff),false);
                                        sayac++;
                                    }
                                    dosyaa.close();
                                    //write.close();
                                //    k.kListeyiListele(0,2);
                                }while(eklendi==false);

                                    if(eklendi==true)
                                    {
                                        k.kdosyayaz(1,k.sefer,git1,git2);
                             write<<"* "<<k.sefer<<" No'lu Sefer // "<<koltuk<<"-> "<<"Fiyat: "<<fi<<" Ad: "<<ad<<" "<<soyad<<" Cinsiyet: "<<cins<<" Durum: "<<durum<<endl;


                                        write.close();
                                        remove(dosyastrng);
                                        rename("gecici2.txt",dosyastrng);
                                        cout<<endl<<endl<<"           !!  ISLEMINIZ BASARIYLA GERCEKLESTI IYI YOLCULUKLAR DILERIZ  !!"<<endl<<endl;

                                    }
                             k.kSonaEkle(k.sefer,k.koltukno,k.kapasit,k.Fiyat,k.mAd,k.mSoyad,k.cinsiyet,k.durum);

            }

                }}}}


    else if(islemno==2)
    {
        cout<<"------------------------------------------------------------- SEFER LISTESI ----------------------------------------------------------------------------"<<endl<<endl;
        ifstream okudosya(dosyastr.c_str());
        string gsatir="";
        int sat=0;
        bool gg=true;
        gitbul(1,false);
            while ( getline(okudosya, gsatir) )
            {
                if(sat<git1)
                {
                     cout<<gsatir<<endl;
                }

                sat++;
            }
                okudosya.close();

            cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<endl<<endl<<endl<<endl;
    }
     else if(islemno==3)
    {
        cout<<"------------------------------------------------ SEFER EKLEME --------------------------------------------------"<<endl<<endl;

        bool gg=true;
        gitbul(1,false);

        cout<<" Guzergah giriniz (orn; Manisa) : ";
        cin>>s.guzergah;
        cout<<endl;

        cout<<"  * Gidis Tarihi :"<<endl;

                cout<<"  Gun(1-31): ";
                cin>>s.gSeferDay;
                cout<<"  Ay (1-12): ";
                cin>>s.gSeferMonth;
                cout<<"  Yil      : ";
                cin>>s.gSeferYear;
                cout<<endl;

        ////////////////////////////////////////////////////////////////////////////////////////////////
        basamak=0;
        tgecici=s.gSeferDay;
        while(tgecici>0)
        {
            tgecici=tgecici/10;
            basamak++;
        }

        if(basamak==1)
        {
            birg=true;
        }
        else
        {
            birg=false;
        }

         basamak=0;
         tgecici=s.gSeferMonth;
         while(tgecici>0)
         {
            tgecici=tgecici/10;
            basamak++;
         }
         if(basamak==1 && birg==true)
         {
            s.gitarih="0"+to_string(s.gSeferDay)+"."+"0"+to_string(s.gSeferMonth)+"."+to_string(s.gSeferYear);
         }
         else if(basamak==1 && birg==false)
         {
            s.gitarih=to_string(s.gSeferDay)+"."+"0"+to_string(s.gSeferMonth)+"."+to_string(s.gSeferYear);
         }
         else if(basamak==2)
         {
            s.gitarih=to_string(s.gSeferDay)+"."+to_string(s.gSeferMonth)+"."+to_string(s.gSeferYear);
         }

        cout<<" Saat giriniz : ";
        cin>>s.gSeferSaat;
        cout<<endl;

        cout<<" Gidis giriniz : ";
        cin>>s.gidis;
        cout<<endl;

        if(s.gidis=="Kocaeli" || s.gidis=="Ankara" || s.gidis=="Istanbul" || s.gidis=="Izmir")
        {
            cout<<" Donus giriniz : ";
            cin>>s.donus;
            cout<<endl;

            if(((s.donus=="Kocaeli" || s.donus=="Ankara" || s.donus=="Istanbul" || s.donus=="Izmir")&& s.donus!=s.gidis) &&
                 (( s.gidis=="Kocaeli" && (s.donus=="Ankara" || s.donus=="Istanbul" || s.donus=="Izmir" ) ||
                   ( s.gidis=="Ankara" && s.donus=="Kocaeli" ) || (s.gidis=="Istanbul" && s.donus=="Kocaeli")||
                   ( s.gidis=="Izmir" && s.donus=="Kocaeli" ) )))
            {
                cout<<" Kapasite giriniz (36,40 veya 44) : ";
                cin>>s.kapasite;
                cout<<endl;

                if(s.kapasite==36 || s.kapasite==40 || s.kapasite==44)
                {
                    cout<<" Fiyat giriniz : ";
                    cin>>s.sFiyat;
                    cout<<endl;

                    cout<<" Plaka giriniz : ";
                    cin.clear();
                    cin.ignore(1);
                    getline(cin,s.sPlaka);
                    cout<<endl;

                    cout<<" Kaptan isim soyisim giriniz : ";
                    getline(cin,s.kaptan);
                    cout<<endl;

                    cout<<" Firma bilgisi giriniz : ";
                     getline(cin,s.firma);
                    cout<<endl;

                    size_t fo = s.firma.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

                    if (fo!=string::npos)
                    {
                        cout<<endl;
                        cout<<" Yanlis karakter girdiniz."<<endl<<endl;
                    }

                   ofstream  dosya(dosyastr.c_str(), ios::app);
                   ofstream  tumu("seferler.txt", ios::app);
                   ifstream dosyaa(dosyastr.c_str());

                   if(dosya.is_open())
                   {
                      string satir ="";
                      strsyc=0;
                      satirsayi=0;
                      while ( getline(dosyaa, satir) )
                      {
                        char strdz[satir.size()+1];
                        strcpy(strdz,satir.c_str());
                        klmsyc=0;
                        char *kelime = strtok(strdz, " ");
                        while (kelime != NULL)
                        {
                            if(strsyc<git1)
                            {

                            if(strsyc>0 && klmsyc==0)
                            {
                                gc=kelime;
                            }

                            if(strsyc>0 && klmsyc==1 && kelime==s.guzergah)
                            {
                                ayni=true;
                            }
                            if(strsyc>0 && klmsyc==1 && kelime!=s.guzergah)
                            {
                                ayni=false;
                            }

                            if(ayni==true && strsyc>0 && klmsyc==2 && kelime==s.gitarih)
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==2 && kelime!=s.gitarih)
                            {
                                ayni=false;
                            }

                            if(ayni==true && strsyc>0 &&klmsyc==3 && kelime==s.gSeferSaat)
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==3 && kelime!=s.gSeferSaat)
                            {
                                ayni=false;
                            }

                            if(ayni==true && ayni==true && strsyc>0 &&klmsyc==4 && kelime==s.gidis)
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==4 && kelime!=s.gidis)
                            {
                                ayni=false;
                            }

                            if(ayni==true && strsyc>0 &&klmsyc==5 && kelime==s.donus)
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==5 && kelime!=s.donus)
                            {
                                ayni=false;
                            }

                            if(ayni==true && strsyc>0 &&klmsyc==6 && kelime==to_string(s.kapasite))
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==6 && kelime!=to_string(s.kapasite))
                            {
                                ayni=false;
                            }

                            if(ayni==true && strsyc>0 && klmsyc==7 && kelime==to_string(s.sFiyat))
                            {
                                ayni=true;
                            }
                            if(ayni==true && strsyc>0 && klmsyc==7 && kelime!=to_string(s.sFiyat))
                            {
                                ayni=false;
                            }

                            if(strsyc>0 && klmsyc==8)
                            {
                                p1=kelime;
                            }
                            if(strsyc>0 && klmsyc==9)
                            {
                                p2=kelime;
                            }
                            if(strsyc>0 && klmsyc==10)
                            {
                                p3=kelime;
                                plk=p1+" "+p2+" "+p3;

                                if(ayni==true && plk==s.sPlaka)
                                {
                                    ayni=true;
                                }
                                else if(ayni==true &&plk!=s.sPlaka)
                                {
                                    ayni=false;
                                }
                            }

                            if(strsyc>0 && klmsyc==11)
                            {
                                kp1=kelime;
                            }
                            if(strsyc>0 && klmsyc==12)
                            {
                                kp2=kelime;
                                kptn=kp1+" "+kp2;
                                if(ayni==true && kptn==s.kaptan)
                                {
                                    ayni=true;
                                }
                                else if(ayni==true && kptn!=s.kaptan)
                                {
                                    ayni=false;
                                }
                            }

                            if(strsyc>0 && ayni==true && klmsyc==13 && kelime==s.firma)
                            {
                                ayni=true;
                                ayni2=true;
                                Seferno=stoi(gc);
                            }
                            if(ayni==true && strsyc>0 && klmsyc==13 && kelime!=s.firma)
                            {
                                ayni=false;
                            }

                           // cout<<"kelime: "<<kelime<<" strsyc: "<<strsyc<<" klmsyc: "<<klmsyc<<endl<<endl;
                            }///////////////////////////////////
                            kelime = strtok(NULL," ");
                            klmsyc++;

                        }
                        strsyc++;
                        satirsayi++;
                    }

                    if(satirsayi==1)
                    {
                        Seferno=1;
                    }
                    if(ayni2==false)
                    {
                        Seferno=stoi(gc)+1;
                    }
                    if(ayni2==false || satirsayi==1)
                     {
                        s.gSeferno=Seferno;

                        PIN=Seferno;
                        cout<<endl<<endl;
                        cout<<" ISLEMINIZ BASARIYLA GERCEKLESTI..."<<endl;
                        cout<<" TEKRAR GORUSMEK DILEGIYLE..."<<endl;
                        cout<<" Sefer numaraniz: "<<PIN<<endl;
                        cout<<" Lutfen sefer numaranizi unutmayiniz.(Silme islemleri icin gerekli olacaktir.) "<<endl;
                        cout<<endl<<endl;

                        s.sSonaEkle(s.gSeferno,s.guzergah,s.gitarih,s.gSeferSaat,s.gidis,s.donus,s.kapasite,s.sFiyat,s.sPlaka,s.kaptan,s.firma);

                        dosya<<endl;
                        tumu<<endl;
                        dosyaa.close();
            dosya<<s.gSeferno<<"              "<<s.guzergah<<"         "<<s.gitarih<<"          "<<s.gSeferSaat<<"      ";
            dosya<<s.gidis<<"     "<<s.donus<<"         "<<s.kapasite<<"            "<<s.sFiyat<<"      "<<s.sPlaka<<"    "<<s.kaptan<<"         "<<s.firma;

            tumu<<s.gSeferno<<"              "<<s.guzergah<<"         "<<s.gitarih<<"          "<<s.gSeferSaat<<"      ";
            tumu<<s.gidis<<"     "<<s.donus<<"         "<<s.kapasite<<"            "<<s.sFiyat<<"      "<<s.sPlaka<<"    "<<s.kaptan<<"         "<<s.firma;
                  }
                  else
                  {
                    cout<<endl<<"              !!!!!!  EKLEMEK ISTEDIGINIZ SEFER ZATEN KAYITLI !!!!!!"<<endl<<endl;
                  }
                }dosya.close();
                tumu.close();
            }
            else
            {
                cout<<"YANLIS GIRIS YAPTINIZ."<<endl;
            }
        }
        else
        {
            cout<<"YANLIS GIRIS YAPTINIZ."<<endl;
        }
      }
      else
      {
          cout<<"YANLIS GIRIS YAPTINIZ."<<endl;
      }

    }
     else if(islemno==4)
    {
        cout<<"       ------------------------------------- SEFER SIL --------------------------------------------"<<endl;

        char eskiad[100];
        char yeniad [100];
        char gecicia [100];
        char gecicib [100];
        wchar_t  str[400];

        FILE *eski,*yeni;
        int silsatir;
        int slsatir;
        char ssatir=0;

        memset(gecicia, '\0', sizeof(gecicib));
        strcpy(eskiad,dosyastrng);
        strcpy(gecicia, eskiad);

        memset(gecicib, '\0', sizeof(gecicib));
        strcpy(yeniad,"replica.txt");
        strcpy(gecicib, yeniad);

        if(silsayac%2==1)
        {
           memset(eskiad, '\0', sizeof(eskiad));
           strcpy(eskiad, gecicia);
           memset(yeniad, '\0', sizeof(yeniad));
           strcpy(yeniad, gecicib);
        }
        else if(silsayac%2==0)
        {
            strcpy(eskiad, gecicib);
            strcpy(yeniad, gecicia);
        }
        bool varmi=false;
        char yesno;
        eski=fopen(eskiad,"r");
        rewind(eski);
        cout<<"Hangi seferi silmek istersiniz: ";
        cin>>slsatir;
        cout<<endl<<endl;
        cout<<" Degistirmek istediginize emin misiniz? (y/n) : ";
        cin>>yesno;
        cout<<endl;

        silsatir=slsatir+1;
        if(yesno=='y')
        {
            yeni=fopen(yeniad,"w");
            while(fgetws(str,400,eski)!=NULL)
            {
                ssatir++;

                if(ssatir!=silsatir)
                {
                    fputws(str,yeni);
                    varmi=true;
                }
            }
            if(varmi==false)
            {
                cout<<"Yanlis satir bilgisi giriniz."<<endl;
            }
            fclose(eski);
            fclose(yeni);

            remove(dosyastrng);
            rename("replica.txt",dosyastrng);
            silsayac++;
            cout<<endl<<"                          !! SILME ISLEMINIZ TAMAMLANDI !!"<<endl<<endl;
        }
        else if(yesno!='y' && yesno!='n')
        {
            cout<<" Hatali giris yaptiniz. "<<endl;
        }

    }
     else if(islemno==5)
    {
        cout<<"                    --------------------- KAPTAN DEGISTIR -------------------------------"<<endl<<endl;

        int deg;
        bool gg=true;
        gitbul(1,false);
        string ykap;
        int seferno,kapasite,fiyat;
        string guzergah,gitarih,saat,gidis,plaka,kaptan,gc,p1,p2,p3,plk,kp1,kp2,kptn,donus,firma,baslik;


        string satir ="";
        strsyc=0;

        cout<<" Degistirmek istediginiz kaptanin sefer numarasini yaziniz : ";
        cin>>deg;
        cout<<endl<<endl;

        ifstream dosyaa(dosyastr.c_str());
        ofstream write("gecici.txt");

        cout << " Yeni kaptan ismi : ";
        cin.clear();
        cin.ignore(1);
        getline(cin,ykap);
        cout<<endl;

        while ( getline(dosyaa, satir) )
        {
          char strdz[satir.size()+1];
          strcpy(strdz,satir.c_str());
          klmsyc=0;
          char *kelime = strtok(strdz, " ");
          while (kelime != NULL)
          {
              if(strsyc<git1)
              {
                            if(strsyc==0)
                            {
                                baslik=kelime;

                            }
                            if(strsyc>0 && klmsyc==0)
                            {
                                gc=kelime;
                                seferno=stoi(gc);
                            }
                            if(strsyc>0 && klmsyc==1)
                            {
                                guzergah=kelime;
                            }

                            if(strsyc>0 && klmsyc==2)
                            {
                                gitarih=kelime;
                            }

                            if(strsyc>0 && klmsyc==3)
                            {
                                saat=kelime;
                            }

                            if(strsyc>0 && klmsyc==4)
                            {
                                gidis=kelime;
                            }

                            if(strsyc>0 && klmsyc==5)
                            {
                                donus=kelime;
                            }
                            if(strsyc>0 &&klmsyc==6)
                            {
                                kapasite=stoi(kelime);
                            }

                            if(strsyc>0 &&klmsyc==7)
                            {
                                fiyat=stoi(kelime);
                            }

                            if(strsyc>0 && klmsyc==8)
                            {
                                p1=kelime;
                            }
                            if(strsyc>0 && klmsyc==9)
                            {
                                p2=kelime;
                            }
                            if(strsyc>0 && klmsyc==10)
                            {
                                p3=kelime;
                                plk=p1+" "+p2+" "+p3;

                                plaka=plk;
                            }

                            if(strsyc>0 && klmsyc==11)
                            {
                                kp1=kelime;
                            }
                            if(strsyc>0&& klmsyc==12)
                            {
                                kp2=kelime;
                                kptn=kp1+" "+kp2;
                                kaptan=kptn;
                            }

                            if(strsyc>0 &&  klmsyc==13)
                            {
                                firma=kelime;
                            }
                    }
            kelime = strtok(NULL," ");
            klmsyc++;
          }
          if (strsyc == deg) {

              write<<seferno<<"              "<<guzergah<<"         "<<gitarih<<"          "<<saat<<"      ";
              write<<gidis<<"     "<<donus<<"         "<<kapasite<<"            "<<fiyat<<"      "<<plaka<<"    "<<ykap<<"         "<<firma;
              write<<endl;
          }
          else
        {
             if(strsyc==0)
               {
                    write<<satir<<endl;
               }
               else if(strsyc<git1)
                {
                  write<<seferno<<"              "<<guzergah<<"         "<<gitarih<<"          "<<saat<<"      ";
                  write<<gidis<<"     "<<donus<<"         "<<kapasite<<"            "<<fiyat<<"      "<<plaka<<"    "<<kaptan<<"         "<<firma;
                  write<<endl;
                }
           }
            strsyc++;
            satirsayi++;
        }
        dosyaa.close();
        write.close();

        ifstream dos(dosyastr.c_str());
        ofstream writee("gecici.txt",ios::app);
        strsyc=0;
        string sat="";

        while ( getline(dos, sat) )
        {
              if(strsyc>=git1)
              {
                writee<<sat<<endl;
              }
              strsyc++;
          }
            dos.close();
            writee.close();
            remove(dosyastrng);
            rename( "gecici.txt",dosyastrng);

            cout<<endl<<endl<<"             !!!!! Isleminiz tamamlandi tebrik ederiz. Ama keske degistirmeseydiniz cok iyi kaptandi..."<<endl;


    }
     else if(islemno==6)
    {
        cout<<"              ------------------------------- GELIR HESAPLA ---------------------------------------------"<<endl<<endl;

        int gsef;
        cout<<"Gelirini hesaplamak istediginiz seferi yaziniz : ";
        cin>>gsef;

        bool eklendi=false;
        int sat=0;
        string karsilastir;
        int oldu;
        int klmsyc;
        gitbul(1,false);
        cout<<endl;
        int stut,ktut;
        bool gec=false;
        int saya=0;

        do
        {
            oldu=1;
            ifstream hdosyaa(dosyastr.c_str());
            string ksatir="";

            strsyc=0;
            while ( getline(hdosyaa, ksatir) )
            {
                char strdz[ksatir.size()+1];
                strcpy(strdz,ksatir.c_str());
                klmsyc=0;
                char *kelime = strtok(strdz, " ");
                while (kelime != NULL)
                {
                    karsilastir =kelime;

                    if(git1>0 && git2>0 && strsyc>=git1 && strsyc<git2)
                    {
                        if(eklendi==false && strsyc==git1 && klmsyc==2 )
                        {
                            if(karsilastir==to_string(gsef))
                            {
                                eklendi=true;
                            }
                        }

                        if(eklendi==true && strsyc>git1 && (klmsyc==2 || klmsyc==5 || klmsyc==8 || klmsyc==11 ))
                        {
                            if(karsilastir=="d")
                            {
                                saya++;
                            }
                        }
                    }
                    kelime = strtok(NULL," ");
                    klmsyc++;
                }

                strsyc++;
                }
                if(eklendi==false)
                {
                    gitbul(gsef,false);
                }
                hdosyaa.close();

                //    k.kListeyiListele(0,2);
            }while(eklendi==false);

                int fiy;

                if(eklendi==true)
                {

                ifstream hdos(dosyastr.c_str());
                string ksatir="";
                strsyc=0;
                int sattut;
                gitbul(1,false);


                while ( getline(hdos, ksatir) )
                {
                    char strdzz[ksatir.size()+1];
                    strcpy(strdzz,ksatir.c_str());
                    klmsyc=0;
                    char *kelime = strtok(strdzz, " ");
                    while (kelime != NULL)
                    {
                        karsilastir=kelime;
                        string gsefs=to_string(gsef);

                        if(strsyc<git1 && strsyc>0 && klmsyc==0 && karsilastir==gsefs)
                        {
                            sattut=strsyc;
                        }
                        if(strsyc==sattut && klmsyc==7)
                        {
                            fiy=stoi(karsilastir);
                        }
                     kelime = strtok(NULL," ");
                     klmsyc++;
                    }
                    strsyc++;
                }
            }
              cout<<endl<<endl;
        cout<<"                                         ** NET GELIR : "<<fiy*saya<<" TL **"<<endl;
        cout<<"                                               TEBRIKLER ! "<<endl<<endl<<endl;
    }
    else if(islemno==7)
    {
        string silsefer;
        cout<<"------------------------------------------ Satis Iptali----------------------------------------------------"<<endl<<endl;
        cout<<" Biletini iptal etmek istediginiz sefer numarasini yaziniz : ";
        cin>>silsefer;
        cout<<endl;

        int sat=0;
        string koltuk,baslik;
        string karsilastir;
        string gdurum;
        string ydurum="b";
        int oldu=1;
        string k1,k2;
        bool eklendi=false;
        int kapasite;
        int klmsyc;
        int farkli;
        bool aynisi=false;
        int sayac=1;
        bool gg=true;
        gitbul(1,false);
        bool degistir=false;
    //    cout<<" Biletini iptal etmek istediginiz otobusun kapasitesini yaziniz : ";
    //    cin>>kapasite;
        cout<<" Biletini iptal etmek istediginiz koltuk numarasini yaziniz : ";
        cin>>k1;
        cout<<endl;
        int stut,ktut;
        bool gec=false;
      do
    {
        oldu=1;
        ifstream dosyaa(dosyastr.c_str());
        ofstream write("gecici2.txt");
        strsyc=0;
        while ( getline(dosyaa, satir) )
        {
            char strdz[satir.size()+1];
            strcpy(strdz,satir.c_str());
            klmsyc=0;
            char *kelime = strtok(strdz, " ");
            while (kelime != NULL)
            {
              karsilastir =kelime;

              if(strsyc<git1)
              {
                  write<<satir<<endl;
              }
              if(git1>0 && git1>0 && strsyc>=git1 && strsyc<git2)
              {
                  if(eklendi==false && strsyc==git1 && klmsyc==2 )
                  {
                      if(karsilastir==silsefer)
                      {
                        k.sefer=stoi(karsilastir);
                        eklendi=true;
                      }
                  }

                  if(eklendi==true && strsyc>git1 && (klmsyc==0 || klmsyc==3 || klmsyc==6 || klmsyc==9 ) )
                  {
                      k.koltukno=karsilastir;

                      if(k.koltukno=="A1")
                      {
                          gec=true;
                      }
                      else
                      {
                        gec=false;
                      }

                      if(k.koltukno==k1)
                      {
                        degistir=true;
                        ktut=klmsyc;
                        stut=strsyc;
                      }
                  }

                  if(eklendi==true && strsyc>git1 && (klmsyc==2 || klmsyc==5 || klmsyc==8 || klmsyc==11 ))
                  {
                      if(karsilastir=="r" && strsyc==stut && klmsyc==ktut+2)
                      {
                          k.durum="b";
                      }
                      if(strsyc!=stut || (strsyc==stut && klmsyc!=ktut+2))
                      {
                          k.durum=karsilastir;
                      }
                      if(k.durum=="b")
                      {
                          k.kapasit=0;
                          k.Fiyat=0;
                          k.mAd="yok";
                          k.mSoyad="yok";
                          k.cinsiyet="yok";
                      }
                      else
                      {
                          k.kapasit=1;
                          k.Fiyat=1;
                          k.mAd="var";
                          k.mSoyad="var";
                          k.cinsiyet="var";
                      }
                      aynisi=true;
                  }

             if((gec==false && eklendi==true && aynisi==true && oldu%3==2))
          {
                //cout<<k.sefer<<" "<<k.koltukno<<" "<<k.kapasit<<" "<<k.Fiyat<<" "<<k.mAd<<" "<<k.mSoyad<<" "<<k.cinsiyet<<" "<<k.durum<<endl;
                k.kSonaEkle(k.sefer,k.koltukno,k.kapasit,k.Fiyat,k.mAd,k.mSoyad,k.cinsiyet,k.durum);
          }
            else if(gec==true && aynisi==true && eklendi==true)
          {
              k.kSonaEkle(k.sefer,k.koltukno,k.kapasit,k.Fiyat,k.mAd,k.mSoyad,k.cinsiyet,k.durum);
          }
            oldu++;
        }
              kelime = strtok(NULL," ");
              klmsyc++;
            }
            strsyc++;
        }
        if(eklendi==false)
        {
         //   cout<<"girdiiiiii "<<endl;

            gg=false;
            gitbul(stoi(silsefer),false);
            sayac++;
        }
        dosyaa.close();
        write.close();

    //    k.kListeyiListele(0,2);
    }while(eklendi==false);

        if(eklendi==true)
        {
            k.kdosyayaz(1,k.sefer,git1,git2);

            remove(dosyastrng);
            rename("gecici2.txt",dosyastrng);

        }
}

     else if(islemno==8)
    {
        ifstream dosyaa(duntarih.c_str());
        ofstream yazdosya(dosyastr.c_str(),ios::app);
        string satir ="";
        int strsyc=0;
        gitbul(1,true);
        while ( getline(dosyaa, satir) )
        {
            if(strsyc<git1)
            {
                yazdosya<<satir<<endl;
            }
            strsyc++;
        }

        dosyaa.close();

        k.kdosyayaz(0,0,5,5);
        cout<<endl<<endl<<"                     !!! DOSYANIZ HAZIR !!!"<<endl<<endl;
    }

    else if(islemno>9 ||islemno<1)
    {
        cout<<"Hatali giris yaptiniz. "<<endl;
    }

}while(islemno<9);
    cout<<endl;
    cout<<" Iyi Gunler... "<<endl;

  //  k.kSondanSil();



    return 0;
}

