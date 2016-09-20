//
//  PokerActor.h
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#ifndef PokerActor_h
#define PokerActor_h

#include "cocos2d.h"

class PokerActor : public cocos2d::CCNode
{
public:
    
    virtual bool init();
    
    // 隨機建立 tempCount 張卡片
    cocos2d::CCArray *getCards(unsigned int tempCount);
    
    // 隨機建立單張卡片
//    cocos2d::CCSprite *
    
};

#endif /* PokerActor_h */
