//
//  ClockTools.h
//  BlockGame
//
//  Created by Coody on 2016/10/6.
//
//

#ifndef ClockTools_h
#define ClockTools_h

#include "cocos2d.h"

typedef enum{
    EnumClockToolsTag_TimeLabel = 10
}EnumClockToolsTag;

class ClockTools : public cocos2d::CCNode{
public:
    virtual bool init();
    CREATE_FUNC(ClockTools);
    
    void setStartTime( unsigned int time );
    void startCount();
    void stopCount();
    
private:
    
};

#endif /* ClockTools_h */
