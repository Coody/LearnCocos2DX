//
//  EndGameScene.h
//  BlockGame
//
//  Created by Coody on 2016/10/7.
//
//

#ifndef EndGameScene_h
#define EndGameScene_h

#include "cocos2d.h"

class EndGameLayer : public cocos2d::CCLayerColor{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(EndGameLayer);
    
private:
    
};

#endif /* EndGameScene_h */
