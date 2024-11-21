#include<fstream>
#include<iostream>
#include<TH1.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TMath.h>
#include<TStyle.h>

using namespace std;

int butuzemi(){
  gStyle->SetOptStat(000000000);

  //Definition
  int event, id1, id2;
  double px1, px2, py1, py2, pz1, pz2, e1, e2;
  double Pt1, Pt2, Zmass;
  ifstream data;

  //sample TCanvas *c1 = new TCanvas("name1", "name2", sizex, sizey);
  TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
  TCanvas *c2 = new TCanvas("c2", "c2", 800, 600);
  TCanvas *c3 = new TCanvas("c3", "c3", 800, 600);
  
  //sample TH1D *h1 = new TH1D("name1", "Title", bin, range_min, range_max);
  
  TH1D *h1 = new TH1D("h1", "h1; particle id;Entry",100,-50,50);
  TH1D *h2 = new TH1D("h2", "h2;Pt1 [GeV];Entry",50,0,100);
  TH1D *h3 = new TH1D("h3", "h3;mass [GeV];Entry",800,0,200);
      
  data.open("ppZ13.dat");

  
  while(data >> event >> id1 >> px1 >> py1 >> pz1 >> e1 >> id2 >> px2 >> py2 >> pz2 >> e2){

    //Task1: particle idのヒストグラム作成
    h1->Fill(id1); //1つ目の粒子のidの値(id1)をヒストグラムh1に詰める
    h1->Fill(id2); //2つ目の粒子のid(id2)をヒストグラムh2に詰める

    cout << "id1:" << id1 << ", id2:" << id2 << endl; //値を出力してみる

    //Task2: Pt1の計算    
    Pt1 = sqrt(px1*px1+py1*py1); // (px1^2 + py1^2)^0.5
    // Pt1 = pow( (pow(px1,2) + pow(py1,2) ), 0.5 )  //こちらでも同じ計算
    h2->Fill(Pt1);
    
    //Task3: Zmassの計算
    
    /********************
      ・Zmass = ?
      ・Zmassの値をh3に詰める
    *********************/

  }

  //option
  h1->SetLineColor(1);
  h1->SetXTitle("particle ID");
  h1->SetLineWidth(2);

  h2->SetLineColor(1);
  h2->SetXTitle("Pt [GeV]");
  h2->SetLineWidth(2);  

  h3->SetLineColor(1);
  h3->SetXTitle("mass [GeV]");
  h3->SetLineWidth(2);
		      
  c1->cd();
  h1->Draw();

  c2->cd();
  h2->Draw();

  c3->cd();
  h3->Draw();

  return 0;
}

