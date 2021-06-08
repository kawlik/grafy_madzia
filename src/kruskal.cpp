#include "kruskal.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

UnikalnyZbior::UnikalnyZbior( int n ) {
    this->n = n;

    this->p = new int [ n + 1 ];
    this->r = new int [ n + 1 ];

    for( int i = 0; i < n + 1; i++ ) {
        this->p[i] = i;
        this->r[i] = 0;
    }
}

int UnikalnyZbior::znajdz( int v ) {

    if( v != this->p[v] ) {
        this->p[v] = this->znajdz( this->p[v] );
    }

    return this->p[v];
}

void UnikalnyZbior::scal( int x, int y ) {

    x = this->znajdz( x );
    y = this->znajdz( y );

    if( this->r[x] > this->r[y] ) {
        this->p[y] = x;

    } else {
        this->p[x] = y;
    }

    if( this->r[x] == this->r[y] ) {
        this->r[x] ++;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( grafMacierz data, bool rysoj ) {

    int rozmiar = data.wezE();
    
    Krawedz * tablica = new Krawedz [rozmiar];
    data.wezWszystkieKrawedzie( tablica );

    sortowanieKopiec< Krawedz >( tablica, rozmiar );

    /*   *   *   *   *   *   *   *   *   *   */

    int weight = 0;         //  waga MST
    vector< Krawedz > M;    //  wektor MST

    UnikalnyZbior zbior( rozmiar );

    for( int i = 0; i < rozmiar; i++ ) {

        int v = tablica[i].v;
        int w = tablica[i].w;

        int V = zbior.znajdz( v );
        int W = zbior.znajdz( w );

        if( V != W ) {

            weight += tablica[i].o;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << tablica[i].o << " ]"<< endl;
            }

            M.push_back( { v, w, tablica[i].o } );            
            zbior.scal( V, W );
        }
    }

    if( rysoj ) {
        cout << " waga MST :  = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */

    // delete [] tablica;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( grafLista data, bool rysoj ) {

    int rozmiar = data.wezE();
    
    Krawedz * tablica = new Krawedz [rozmiar];
    data.wezWszystkieKrawedzie( tablica );

    sortowanieKopiec< Krawedz >( tablica, rozmiar );

    /*   *   *   *   *   *   *   *   *   *   */

    int weight = 0;         //  waga MST
    vector< Krawedz > M;    //  wektor MST

    UnikalnyZbior zbior( rozmiar );

    for( int i = 0; i < rozmiar; i++ ) {

        int v = tablica[i].v;
        int w = tablica[i].w;

        int V = zbior.znajdz( v );
        int W = zbior.znajdz( w );

        if( V != W ) {

            weight += tablica[i].o;

            if( rysoj ) {
                cout << v << " -> " << w << " | [ " << tablica[i].o << " ]"<< endl;
            }

            M.push_back( { v, w, tablica[i].o } );            
            zbior.scal( V, W );
        }
    }

    if( rysoj ) {
        cout << " waga MST :  = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */

    // delete [] tablica;
}
