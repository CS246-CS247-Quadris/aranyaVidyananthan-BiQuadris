#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H

using namespace std;

class Biquadris{

   Board* boardOne;
   Board* boardTwo;
  
   int ScoreOne;
   int ScoreTwo;

   public:
   Biquadris();
   ~Biquadris();
   void ClearBoards();

};

#endif
