#include<fstream>
#include<iostream>
#include<TH1.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TMath.h>
#include<TStyle.h>

using namespace std;

int hist(){
  gStyle->SetOptStat(000000000);

  //Definition
  int event, id1, id2;
  double px1, px2, py1, py2, pz1, pz2, e1, e2, Zmass,Pt1;
  ifstream data;

  //sample TCanvas *c1 = new TCanvas("name1", "name2", sizex, sizey);
  TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
  
  //sample TH1D *h1 = new TH1D("name1", "name2", bin, range_min, range_max);
  
  TH1D *h1 = new TH1D("h1", "h1;Pt [GeV];Entry",50,0,100);
  TH1D *h2 = new TH1D("h2", "h2;mass [GeV];Entry",800,0,200);
		      
  data.open("ppZ13.dat");

  
  while(data >> event >> id1 >> px1 >> py1 >> pz1 >> e1 >> id2 >> px2 >> py2 >> pz2 >> e2){
    //Ptの計算    
    Pt1 = sqrt(px1*px1+py1*py1);
    h1->Fill(Pt1);
    
    //Zmassの計算
    Zmass =sqrt(pow((e1+e2),2)-pow((px1+px2),2)-pow((py1+py2),2)-pow((pz1+pz2),2));
    h2->Fill(Zmass);
  }

  //option
  //h1->SetLineColor(1);
  //h1->SetXTitle("Pt [GeV]");
  //h1->SetLineWidth(2);

  h2->SetLineColor(1);
  h2->SetXTitle("mass [GeV]");
  h2->SetLineWidth(2);
		      

  h2->Draw();

  return 0;
}

