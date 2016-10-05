//
//  LogoScene.h
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef LogoScene_h
#define LogoScene_h

#include "cocos2d.h"

class LogoLayer : public cocos2d::CCLayerColor{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(LogoLayer);
    
};

#endif /* LogoScene_hpp */
