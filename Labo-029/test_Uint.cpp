#include "Uint.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string nombre;
  cout << "Introduire un nombre entier: ";
  cin >> nombre;
  size_t nb = stoul(nombre);
  Uint n;           // Vérification constructeur vide   
  n = Uint(nombre); // Vérification constructeur par string
  
  cout << "Nombre lu " << n << endl; // Vérification opérateur <<

  Uint factorielle(1); // Vérification constructeur par entier (explicite)
  cout << factorielle << endl;
  for (size_t i = 2; i <= nb; ++i)
  {
    factorielle *= i; // Vérification *= size_t
    cout << i << "! = " << factorielle << endl;
  }

  factorielle = 1; // Vérification constructeur par entier implicite
  for (Uint i = 2; i <= n; ++i) // Vérification <= et ++
  {
    factorielle *= i; // Vérification *= Uint
    cout << i << "! = " << factorielle << endl;
  }

  Uint fibo_m2(0), fibo_m1(1), fibonacci;
  for (Uint i = 2; i <= n; ++i) 
  {
    fibonacci = fibo_m2 + fibo_m1; // Vérification Uint + Uint
    cout << "fibonacci(" << i << ") = " << fibonacci << endl;
    fibo_m2 = fibo_m1;
    fibo_m1 = fibonacci;
  }

  // Vérification -, > et -=
  for (Uint i = n - 2; i > 0; i -= 1) 
  {
    cout << "fibonacci(" << i << ") = " << fibo_m2 << endl;
    fibonacci = fibo_m1;
    fibo_m1 = fibo_m2;
    fibo_m2 = fibonacci - fibo_m2; // Vérification -
  }

  for (Uint i = n; i > 0; i -= 1)
  { 
    cout << i << "! = " << factorielle << endl;
    factorielle = factorielle / i; // Vérification Uint/Uint
  }
    
  Uint p;
  do
  { 
    p = gen_random(nb); // Vérification gen_random
    cout << p << endl;
  } while (!prime(p));  // Vérification exponentiation modulaire, prime
}

