/*
* Util class with static functions
*
*/

#ifndef _UTILS_H
#define _UTILS_H

class Utils {
protected:
    Utils(void);

public:
    virtual ~Utils(void) = 0;

    static unsigned int GetRandomUIntInRange(unsigned int a, unsigned int b);
};

#endif