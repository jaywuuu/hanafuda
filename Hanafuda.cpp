/*
* Hanafuda game base class
*
*/

#include "Hanafuda.h"
#include "Utils.h"

Hanafuda::Hanafuda(void) {
    memset(m_CardData, 0, HANAFUDA_NUM_CARDS*sizeof(HANAFUDA_CARD));
    SetupCards();
}

Hanafuda::~Hanafuda(void) {

}

HANAFUDA_CARD* Hanafuda::GetCard(CARD_ID id) {
    HANAFUDA_CARD *card = NULL;

    if (id >= 0 && id < HANAFUDA_NUM_CARDS) {
        card = &m_CardData[id];
    }

    return card;
}

void Hanafuda::Shuffle(void) {
    unsigned int currDeckSize = m_Deck.size();

    if (currDeckSize > 1 && currDeckSize <= HANAFUDA_DECK_SIZE) {
        CARD_ID tempDeck[HANAFUDA_DECK_SIZE];
        memset(tempDeck, 0, HANAFUDA_DECK_SIZE*sizeof(CARD_ID));
    
        // pop everything off the current deck
        for (unsigned int i = 0; i < currDeckSize; ++i) {
            tempDeck[i] = m_Deck.top();
            m_Deck.pop();
        }

        if (m_Deck.empty()) {
            // knuth shuffle temp deck.
            for (unsigned int i = 0; i < currDeckSize; ++i) {
                if (i < currDeckSize - 1) {
                    unsigned int randIdx = Utils::GetRandomUIntInRange(i, currDeckSize - 1);

                    if (i != randIdx) {
                        CARD_ID tempCardId = tempDeck[i];
                        tempDeck[i] = tempDeck[randIdx];
                        tempDeck[randIdx] = tempCardId;
                    }
                }

                // push back onto the stack.
                m_Deck.push(tempDeck[i]);
            }
        }
        else {
            // error
        }

        if (m_Deck.size() != currDeckSize) {
            // error
        }
    }
}

/*
* Return:
*       true if successful
*       false if unsuccessful
*/
bool Hanafuda::DrawCardFromTop(HANAFUDA_CARD *pOut) {
    bool retval = false;

    if (pOut != NULL && !m_Deck.empty()) {
        CARD_ID cardId = m_Deck.top();
        m_Deck.pop();

        memcpy(pOut, &m_CardData[cardId], sizeof(HANAFUDA_CARD));
        retval = true;
    }

    return retval;
}

void Hanafuda::SetupCards(void) {
    unsigned int i = 0;

    // Matsu - Pine
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MATSU,      HANAFUDA_CARD_TYPE__NORMAL,         1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MATSU,      HANAFUDA_CARD_TYPE__NORMAL,         1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MATSU,      HANAFUDA_CARD_TYPE__POEM_RIBBON,    5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MATSU,      HANAFUDA_CARD_TYPE__SPECIAL_CRANE,  20 };

    // Ume - Plum blossom
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__UME, HANAFUDA_CARD_TYPE__NORMAL,            1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__UME, HANAFUDA_CARD_TYPE__NORMAL,            1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__UME, HANAFUDA_CARD_TYPE__POEM_RIBBON,       5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__UME, HANAFUDA_CARD_TYPE__SPECIAL_WARBLER,   10 };

    // Sakura - cherry blossom
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SAKURA, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SAKURA, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SAKURA, HANAFUDA_CARD_TYPE__POEM_RIBBON,        5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SAKURA, HANAFUDA_CARD_TYPE__SPECIAL_CURTAIN,    20 };

    // Fuji - wisteria
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__FUJI, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__FUJI, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__FUJI, HANAFUDA_CARD_TYPE__RED_RIBBON,       5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__FUJI, HANAFUDA_CARD_TYPE__SPECIAL_CUCKOO,   10 };

    // Ayame - iris
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__AYAME, HANAFUDA_CARD_TYPE__NORMAL,          1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__AYAME, HANAFUDA_CARD_TYPE__NORMAL,          1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__AYAME, HANAFUDA_CARD_TYPE__RED_RIBBON,      5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__AYAME, HANAFUDA_CARD_TYPE__SPECIAL_IRIS,    10 };

    // Botan - peony
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__BOTAN, HANAFUDA_CARD_TYPE__NORMAL,                  1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__BOTAN, HANAFUDA_CARD_TYPE__NORMAL,                  1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__BOTAN, HANAFUDA_CARD_TYPE__PURPLE_RIBBON,           5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__BOTAN, HANAFUDA_CARD_TYPE__SPECIAL_BUTTERFLIES,     10 };

    // Hagi - bush clover
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__HAGI, HANAFUDA_CARD_TYPE__NORMAL,       1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__HAGI, HANAFUDA_CARD_TYPE__NORMAL,       1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__HAGI, HANAFUDA_CARD_TYPE__RED_RIBBON,   5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__HAGI, HANAFUDA_CARD_TYPE__SPECIAL_BOAR, 10 };

    // Susuki - susuki grass
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SUSUKI, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SUSUKI, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SUSUKI, HANAFUDA_CARD_TYPE__SPECIAL_GEESE,      10 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__SUSUKI, HANAFUDA_CARD_TYPE__SPECIAL_MOON,       20 };

    // Kiku - chrysanthemum
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIKU, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIKU, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIKU, HANAFUDA_CARD_TYPE__PURPLE_RIBBON,    5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIKU, HANAFUDA_CARD_TYPE__SPECIAL_SAKE,     10 };

    // Momiji - maple
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MOMIJI, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MOMIJI, HANAFUDA_CARD_TYPE__NORMAL,             1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MOMIJI, HANAFUDA_CARD_TYPE__PURPLE_RIBBON,      5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__MOMIJI, HANAFUDA_CARD_TYPE__SPECIAL_DEER,       10 };

    // Yanagi - willow
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__YANAGI, HANAFUDA_CARD_TYPE__RED_RIBBON,         5 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__YANAGI, HANAFUDA_CARD_TYPE__SPECIAL_LIGHTNING,  1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__YANAGI, HANAFUDA_CARD_TYPE__SPECIAL_SWALLOW,    10 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__YANAGI, HANAFUDA_CARD_TYPE__SPECIAL_RAINMAN,    20 };

    // Kiri - paulownia
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIRI, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIRI, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIRI, HANAFUDA_CARD_TYPE__NORMAL,           1 };
    m_CardData[i++] = { HANAFUDA_CARD_SUIT__KIRI, HANAFUDA_CARD_TYPE__SPECIAL_PHOENIX,  20 };
}

void Hanafuda::SetupDeck(void) {
    if (m_Deck.empty()) {
        for (unsigned int i = 0; i < HANAFUDA_DECK_SIZE; ++i) {
            m_Deck.push(i);
        }
    }
}

void Hanafuda::ClearDeck(void) {
    if (!m_Deck.empty()) {
        for (unsigned int i = 0; i < m_Deck.size(); ++i) {
            m_Deck.pop();
        }
    }
}

// Not implemented in base class
int Hanafuda::ScoreHand(CARD_ID *pHand, unsigned int handSize) {
    return 0;
}