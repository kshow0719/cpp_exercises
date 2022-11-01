#include "shape.h"
#include "rectangle.h"
#include "disk.h"

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

    return 0;
}