#include "shape.h"
#include "rectangle.h"
#include "disk.h"
#include "polygon.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "stdio.h"
#include "iostream"
using namespace std;

int main(void){
    // Rectangle テスト
    cout << "----------- Test for Rectangle -----------" << endl;
    Point p;
    float w, h, area, area_new, area_clo;
    string name, name_new, name_clo;
    p.x = 0;
    p.y = 0;
    w = 4;
    h = 5;

    Rectangle Rec(p, w, h);
    name = Rec.get_name();
    area = Rec.compute_area();
    cout << "Rec: name = "<< name << ", area = " << area << endl;

    // create テスト
    Rectangle Rec_new = *Rec.create();
    name_new = Rec_new.get_name();
    area_new = Rec_new.compute_area();
    cout << "Rec_new: name_new = "<< name_new << ", area_new = " << area_new << endl;

    // clone テスト
    Rectangle Rec_clo = *Rec.clone();
    name_clo = Rec_clo.get_name();
    area_clo = Rec_clo.compute_area();
    cout << "Rec_clo: name_clo = " << name_clo << ", area_clo = " << area_clo << endl;

    cout << "------------- Test for Disk --------------" << endl;
    float r;
    r = 6;

    Disk disk(p, r);
    name = disk.get_name();
    area = disk.compute_area();
    cout << "Disk: name = "<< name << ", area = " << area << endl;

    // create テスト
    Disk disk_new = *disk.create();
    name_new = disk_new.get_name();
    area_new = disk_new.compute_area();
    cout << "disk_new: name_new = "<< name_new << ", area_new = " << area_new << endl;

    // clone テスト
    Disk disk_clo = *disk.clone();
    name_clo = disk_clo.get_name();
    area_clo = disk_clo.compute_area();
    cout << "Rec_clo: name_clo = " << name_clo << ", area_clo = " << area_clo << endl;


    cout << "------------- Test for Polygon --------------" << endl;
    int NoV = 4;
    float Radius = 5;
    Point vertex[100];

    // Vertex
    vertex[0].x = -1;
    vertex[0].y = -1;
    vertex[1].x = 2;
    vertex[1].y = -1;
    vertex[2].x = 2;
    vertex[2].y = 1;
    vertex[3].x = -1;
    vertex[3].y = 1;


    Polygon Pol(NoV, vertex);
    name = Pol.get_name();
    area = Pol.compute_area();
    cout<< "Pol: name = " << name << ", area = " << area << endl;

    // create テスト
    Polygon Pol_new = *Pol.create();
    name_new = Pol_new.get_name();
    area_new = Pol_new.compute_area();
    cout<< "Pol_new: name_new = " << name_new << ", area_new = " << area_new << endl;

    // clone テスト
    Polygon Pol_clo = *Pol.clone();
    name_clo = Pol_clo.get_name();
    area_clo = Pol_clo.compute_area();
    cout<< "Pol_clo: name_clo = " << name_clo << ", areacl = " << area_clo << endl;

    cout << "------------- Test for 64 vertex --------------" << endl;
    //64vertex
    NoV = 64;
    for(int i = 0; i < 64; i++){
        //ラジアン ＝ 度*π/180
        double rad = (360*i/64)*M_PI/180;
        vertex[i].x = Radius*cos(rad);
        vertex[i].y = Radius*sin(rad);
    }

    // Polygon テスト
    Polygon Pol64(NoV, vertex);
    name = Pol64.get_name();
    area = Pol64.compute_area();
    cout<< "Pol64: name = " << name << ", area = " << area << endl;

    // create テスト
    Pol_new = *Pol64.create();
    name_new = Pol_new.get_name();
    area_new = Pol_new.compute_area();
    cout<< "Pol_new name_new = " << name_new << ", areacr = " << area_new << endl;

    // clone テスト
    Pol_clo = *Pol64.clone();
    name_clo = Pol_clo.get_name();
    area_clo = Pol_clo.compute_area();
    cout<< "Pol_clo: name_clo = " << name_clo << ", areacl = " << area_clo << endl;

    // Disk (radius = 5)
    Disk Disk5(p,Radius);
    string name_disk;
    float area_disk;
    name_disk = Disk5.get_name();
    area_disk = Disk5.compute_area();
    cout<< "Disk5: name_disk = " << name_disk << ", area_disk = " << area_disk << "\n";

    return 0;
}