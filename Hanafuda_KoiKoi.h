/*
* Hanafuda Koi Koi game class
*
*/

#ifndef _HANAFUDA_KOIKOI_H
#define _HANAFUDA_KOIKOI_H

#include "Hanafuda.h"

typedef unsigned int PLAYER_ID;

class Hanafuda_KoiKoi : public Hanafuda {
private:
    PLAYER_ID m_parentPlayer;

public:
    Hanafuda_KoiKoi(void);
    virtual ~Hanafuda_KoiKoi(void);

    virtual void StartGame(PLAYER_ID parentPlayer);

    virtual int ScoreSet(CARD_ID *pHand, unsigned int handSize);
};

#endif