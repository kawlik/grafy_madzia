#include "kruskal.hh"
#include "prima.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main() {

    srand( time(NULL) );
    grafLista graf( 500 );
    // grafMacierz graf( 500 );

    graf.wypelnij( 100 ); 

    // graf.rysoj();
    cout << endl << endl;

    // Kruskal( graf, true );
    Prima( graf, true );
}