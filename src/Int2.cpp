#include "Int2.h"

Int2 Int2::operator  + (const Int2 other){ return Int2(x+other.x,y+other.y); }
Int2 Int2::operator - (const Int2 other){return Int2(x-other.x,y-other.y); }

Int2 Int2::operator / (const int other){ return Int2(x/other,y/other); }
Int2 Int2::operator * (const int other){ return Int2(x*other,y*other); }
