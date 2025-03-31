#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

namespace functions {
  void calc(int time) {
    this_thread::sleep_for(chrono::seconds(time));  // Simula un cálculo que toma tiempo
    cout << "El hilo " << this_thread::get_id() << " finalizo despues de " << time << " segundos." << endl;
  }
} 

int main() {
  #pragma omp parallel sections num_threads(2)
  {
    #pragma omp section 
    { 
      // Hilo 1
      functions::calc(3); 
    }
    #pragma omp section 
    { 
      // Hilo 2
      functions::calc(1); 
    }
  }
}