#include "PoligonoIrre.h"
#include <iostream>
#include <bits/stdc++.h> 
#include<stdlib.h>
#include<time.h>
#include <iomanip>
#include <algorithm>  

using namespace std;

int PoligonoIrre::tam=0;

bool cmd(Coordenada c1,Coordenada c2){
    return c1.getManitud()<c2.getManitud();
}
PoligonoIrre::PoligonoIrre()
{
}

int PoligonoIrre::tamVector(){
    return v.size();
}

void PoligonoIrre::imprimeVertices(){
    cout<<endl;
    /*
    for(int i=0;i<v.size();i++){
        cout<<"Vertice["<<i<<"]: ("<<v[i].obtenerX()<<","<<v[i].obtenerY()<<")"<<endl;
    }*/
    int x=1;
    vector<Coordenada>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<fixed<<setprecision(3)<<"Vertice["<<x<<"]:("<<it->obtenerX()<<","<<it->obtenerY() <<")"<<" Magnitud: "<<it->getManitud()<<endl;
        x++;
    }
    cout<<endl;
}

void PoligonoIrre::agregarCoordenada(double x,double y,int pos){
    Coordenada coordenada(x,y);
    //cout << "recibido; " << x << endl;
    v[pos]=coordenada;
}

void PoligonoIrre::setTam(int tt){
    v.resize(tt);
    tam+=tt;
}
//Metodo estatico
int PoligonoIrre::getTam(){
    return tam;
}

void PoligonoIrre::obtenerA(){
    vector<Coordenada>::iterator it;
      
    sort(v.begin(),v.end(),cmd);

    for(it=v.begin();it!=v.end();it++){
        int x=0;
        cout<<fixed<<setprecision(3)<<"Vertice["<<x<<"]:("<<it->obtenerX()<<","<<it->obtenerY() <<")"<<" Magnitud: "<<it->getManitud()<<endl;
        x++;
    }
    cout<<endl;
}