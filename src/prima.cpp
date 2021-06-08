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

    int index = 0;
    int weight = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( index < data.wezV() - 1 ) {

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

            index++;
            weight += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysoj ) {
        cout << "MST weight = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    delete [] wMST;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafMacierz data, bool rysoj ) {

    bool * wMST;

    wMST = new bool [ data.wezV() ];
    for( int i = 0; i < data.wezV(); i++ ) {
        wMST[i] = false;
    }

    wMST[0] = true;

    int index = 0;
    int weight = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( index < data.wezV() - 1 ) {

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

            index++;
            weight += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysoj ) {
        cout << "MST weight = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    delete [] wMST;
}