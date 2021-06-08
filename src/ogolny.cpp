#include "ogolny.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Krawedz::operator = ( Krawedz data ) {
    this->v = data.v;
    this->w = data.w;
    this->o = data.o;
}

bool Krawedz::operator > ( Krawedz data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Krawedz::operator < ( Krawedz data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Krawedz::operator == ( Krawedz data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Krawedz::operator >= ( Krawedz data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Krawedz::operator <= ( Krawedz data ) { if( this->o > data.o ) { return true; } else { return false; } }

istream & operator >> ( istream & str, Krawedz & data ) {
    str >> data.v >> data.w >> data.o;
    return str;
}

ostream & operator << ( ostream & str, Krawedz & data ) {
    str << " ( " << data.v << " -> " << data.w << " | [ " << data.o << " ] ) ";
    return str;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */