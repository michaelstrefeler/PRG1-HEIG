#include <iostream>

using namespace std;

double pyramid_volume(double length, double width, double height)
{
    return (width*length*height)/3.0;
}

int main(){
    double length, width, height;
    cout << "Longeur, largeur, hauteur: ";
    cin >> length >> width >> height;
    cout << "Volume de la pyramide est: " 
         << pyramid_volume(length, width, height) << endl;
}