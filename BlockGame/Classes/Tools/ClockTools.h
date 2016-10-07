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

#define D_ClockTools_BasicTick (1)

typedef enum{
    EnumClockToolsTag_TimeLabel = 10
}EnumClockToolsTag;

class ClockTools : public cocos2d::CCNode{
public:
    virtual bool init();
    CREATE_FUNC(ClockTools);
    
    void setNumberColor( const cocos2d::ccColor3B& color );
    void setNumberLayerAlpha( float alphaValue );
    void setStartTimeAndTick( float basicTick);
    void setStartTimeAndTick( float basicTick , unsigned int time );
    void setMaxTime( unsigned int maxTime );
    void startCount();
    void stopCount();
    
private:
    void calculate();
    float m_fBasicTick;
    float m_fTotalTime;
    unsigned int m_uiMaxTime;
};

#endif /* ClockTools_h */
