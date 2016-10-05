//
//  ActionTools.hpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/1.
//
//

#ifndef ActionTools_h
#define ActionTools_h

#include "cocos2d.h"

class ActionTools : public cocos2d::CCNode{
public:
    
    static cocos2d::CCSequence *getHeartBitAnimation();
    
    static cocos2d::CCSequence *getShowAnimation(float scaleBig,
                                                 float bigRate,
                                                 float scaleSmall,
                                                 float smallRate);
    
    static cocos2d::CCSequence *getHideAnimation(float scaleBig,
                                                 float bigRate,
                                                 float scaleSmall,
                                                 float smallRate);
};

#endif /* ActionTools_h */
