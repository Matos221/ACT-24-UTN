
//ACTIVIDAD 24
#include <iomanip>
#include <iostream>
#include <conio.h>

using namespace std;

//DATOS A USAR
typedef char str20[21];

struct RVent{
    short Codven, cantVend;
    str20 descrip;
    float precUnit;
    };

    int cantVend;

//typedef float Totgnl, Maximp;
//typedef short CodventAnt;//CodventAnt


RVent Rvendedor;

//PROTOTIPOS DE FUNCIONES

    void EmitTitCab(float Totgnl, float Maximp);
    void ObtDatos(RVent Rvendedor);
    void EmitIniCabVent(short codVen, short codVentAnt, float Totitem);
    void CalcDet(RVent Rvendedor, float Totitem, float Totvend);
    void EmitLiDet(RVent Rvendedor, float Totitem);
    void CalVerif(float Totvend,float Totgnl, float Maximp, short CodvenMax, short codVentAnt);
    void EmitPieVen(float Totvend);
    void EmitPieLis(float Totgnl, short CodvenMax);


//********************
int main(){
    // Declaracion de funciones
    short Codven, CodventAnt, CodvenMax;
    float Totalgna, MaxImpo, TotalVend, NimItem, TotalItem;
    float Maximp;
    str20 Descrip;

    RVent Svendedor;

    EmitTitCab(Totalgna, MaxImpo);
    ObtDatos(Svendedor);

    while (Svendedor.Codven != 0){
    EmitIniCabVent(Codven, CodventAnt, TotalItem);

        while(Svendedor.Codven == CodventAnt ){
        CalcDet(Svendedor, TotalItem, TotalVend);
        EmitLiDet(Svendedor, TotalItem);
        ObtDatos(Svendedor);
        }
     CalVerif(TotalVend, Totalgna, Maximp, CodvenMax, CodventAnt);
     EmitPieVen(TotalVend);
    }
     EmitPieLis(Totalgna, CodvenMax);

    getch();
    return 0;

}

//********************

//FUNC EMITIR PRIMEROS TITULOS
void EmitTitCab(float Totgnl, float Maximp){
    cout<<"Ventas de vendedores agrupadas por codigo del vendedor"<<endl;
    cout<<"Totales por codigo de vendedor y Total general + codigo del vendedor con mayor aporte"<<endl;
    Totgnl = 0;
    Maximp = 0;
}

//FUNC OBTENER DATOS/*
void ObtDatos(RVent Rvendedor){

    cout<<"Datos del vendedor: ";
    cout<<"Codigo / para FINALIZAR ingresar ==> 0";
    cin >> Rvendedor.Codven;
    if (Rvendedor.Codven == 0){
        cout<<"Cantidad.......:"; cin>>Rvendedor.cantVend;
        cout<<"Descrip del item.....:";cin.get(Rvendedor.descrip,20);
        cout<<"Precio Unitario..:"; cin>>Rvendedor.precUnit;
    }
}
//FUNC DE EMITIR SEGUNDOS TITULOS
void EmitIniCabVent(short codVen, short codVentAnt, float Totitem){

    Totitem = cantVend * Rvendedor.precUnit;
    codVentAnt = codVen;
    cout<<"Codigo del vendedor: "<<codVen<<endl;
    cout<<" Cant.Descripcion:               Prec.Unit:       Total.Item:"<<endl;
    Totvend= 0.0;
    codVentAnt = codVen;
}


//FUNC CALCULOS
void CalcDet(RVent Rvendedor, float Totitem, float Totvend){
    Totitem = Rvendedor.cantVend * Rvendedor.precUnit;
    Totvend += Totitem;
}

//FUNC EMITIR DETALLES
void EmitLiDet(RVent Rvendedor float Totitem){

    cout<<Rvendedor.cantVend<<endl;
    cout<<"*\n-----------------------------------------------------------------*"<<endl;
    cout<<Rvendedor.descrip<<endl;
    cout<<"*\n-----------------------------------------------------------------*"<<endl;
    cout<<Rvendedor.precUnit<<endl;
    cout<<"*\n-----------------------------------------------------------------*"<<endl;
    cout<<Totitem<<endl;
}

//FUNC CALCULAR Y VERIFCAR
void CalVerif(float Totvend,float Totgnl, float Maximp, short CodvenMax, short CodventAnt){
    Totgnl += Totvend;
    if(Totvend > Maximp){
        Maximp = Totvend;
        CodvenMax = CodventAnt;
    }
}

//FUNC EMITIR PIE VENTAS
void EmitPieVen(float Totvend){
    cout<<"Total del vendedor: "<<Totvend<<endl;
}

//FUNC EMITIR PIE FINAL
void EmitPieLis(float Totgnl, short CodvenMax){
    cout<<"\nEl vendedor con mayor importe fue: "<<CodvenMax<<endl;
    cout<<"Y el total de todas la ventas fue: "<<Totgnl<<endl;

}


