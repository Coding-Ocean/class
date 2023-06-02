#include<iostream>
#include"ascii.h"
using namespace std;
//基底クラス
class CAST
{
private:
    //メンバ変数
    string Name;
    int Age;
public:
    //メンバ関数
    //コンストラクタ
    CAST() 
    { 
        Name = "名無し"; 
        Age = 0; 
    }
    //デストラクタ
    virtual ~CAST() 
    { 
        cout << Name << "「では、さようなら。」" << endl; 
    }
    //自己紹介する
    virtual void introduceHerself() 
    { 
        cout << Name << ' ' << Age << "才です。" << endl; 
    }
    //ゲッター
    string name() 
    { 
        return Name; 
    }
    int age() 
    { 
        return Age; 
    }
protected:
    //引数ありコンストラクタ
    CAST(string name, int age) 
    { 
        Name = name; 
        Age = age; 
    }
    //セッター
    void name(string name) 
    { 
        Name = name; 
    }
    void age(int age) 
    { 
        Age = age; 
    }
};
//派生クラス
class HITAGI : public CAST
{
public:
    //基底クラスの引数ありコンストラクタを指定して呼び出す
    HITAGI() 
        : CAST("戦場ヶ原ひたぎ",18)
    {
    }
    ~HITAGI() 
    { 
        cout << "切り落とすわよ" << endl; 
    }
    //オーバーライド
    void introduceHerself() 
    {
        hitagi_ascii();
        cout << "ショーツとブラは、柄物しか持っていないの。" << endl;
    }
};
class HANEKAWA : public CAST{
public:
    HANEKAWA() 
        : CAST("羽川翼",18)
    {
    }
    void introduceHerself() 
    {
        hanekawa_ascii();
        cout << "わたしはとてもエッチです。" << endl;
    }
};
class HATIKUJI : public CAST{
public:
    HATIKUJI() 
        : CAST("八九寺真宵", 12)
    {
    }
    void introduceHerself() 
    {
        hatikuji_ascii();
        cout << "噛みまみた。" << endl;
    }
};
class KANBARU : public CAST 
{
public:
    KANBARU() 
    { 
        name("神原駿河"); 
        age(17); 
    }
    void introduceHerself() 
    {
        kanbaru_ascii();
        cout << "職業は阿良々木先輩のエロ奴隷だ。" << endl;
    }
};

int main(){
    //{
    //    //インスタンス(実例)をつくる
    //    HITAGI hitagi;
    //    HANEKAWA hanekawa;
    //    HATIKUJI hatikuji;
    //    KANBARU kanbaru;
    //    //自己紹介する
    //    hitagi.introduceHerself();
    //    hanekawa.introduceHerself();
    //    hatikuji.introduceHerself();
    //    kanbaru.introduceHerself();
    //}
    //cout << endl;
    {
        //基底クラスのポインタに
        //派生クラスのインスタンスのアドレスを入れる
        //インスタンス(実例)をつくる
        CAST* casts[] = {
            new HITAGI,  
            new HANEKAWA,
            new HATIKUJI,
            new KANBARU, 
        };
        //多態性
        for (CAST* cast : casts) {
            //CAST::introduceHerself()にはvirtualを付けておかないと
            //派生クラスでオーバーライドした関数は呼び出されない。
            cast->introduceHerself();
        }
        //解放
        //CAST::~CAST()にはvirtualを付けておかないと
        //派生クラスのデストラクタは呼び出されない。
        cout << endl;
        for (CAST* cast : casts) {
            delete cast;
        }
    }
    system("pause>0");
}