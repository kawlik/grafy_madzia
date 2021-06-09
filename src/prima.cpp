#include "prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool wZbiorzeMST( int v, int w, bool * wMST ) {

    if( v == w ) { return false; }

    if( wMST[v] && wMST[w] ) { return false; }

    if( !wMST[v] && !wMST[w] ) { return false; }

    return true;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafLista data, bool rysoj ) {

    bool * wMST;

    wMST = new bool [ data.wezV() ];
    for( int i = 0; i < data.wezV(); i++ ) {
        wMST[i] = false;
    }

    wMST[0] = true;

    int indeks = 0;
    int waga = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( indeks < data.wezV() - 1 ) {

        int min = INF;
        int v = -1;
        int w = -1;

        for( int i = 0; i < data.wezV(); i++ ) {
            for( int j = 0; j < data.wezV(); j++ ) {
                
                if( !data.saSasiednie( i, j ) ) { continue; }

                if( data.wezKrawedz( i, j ).o < min ) {

                    if( wZbiorzeMST( i, j, wMST )) {

                        min = data.wezKrawedz( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) {

            indeks++;
            waga += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysoj ) {
        cout << "MST waga = " << waga << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    // delete [] wMST;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafMacierz data, bool rysoj ) {

    bool * wMST;

    wMST = new bool [ data.wezV() ];
    for( int i = 0; i < data.wezV(); i++ ) {
        wMST[i] = false;
    }

    wMST[0] = true;

    int indeks = 0;
    int waga = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( indeks < data.wezV() - 1 ) {

        int min = INF;
        int v = -1;
        int w = -1;

        for( int i = 0; i < data.wezV(); i++ ) {
            for( int j = 0; j < data.wezV(); j++ ) {
                
                if( !data.saSasiednie( i, j ) ) { continue; }

                if( data.wezKrawedz( i, j ).o < min ) {

                    if( wZbiorzeMST( i, j, wMST )) {

                        min = data.wezKrawedz( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) {

            indeks++;
            waga += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysoj ) {
        cout << "MST waga = " << waga << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    // delete [] wMST;
}