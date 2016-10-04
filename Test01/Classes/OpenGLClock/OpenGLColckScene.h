//
//  OpenGLColckScene.h
//  Test01
//
//  Created by Coody on 2016/9/29.
//
//

#ifndef OpenGLColckScene_h
#define OpenGLColckScene_h

#include "cocos2d.h"

class OpenGLClockLayer : public cocos2d::CCLayerColor
{
public:
    
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(OpenGLClockLayer);
    
};

#endif /* OpenGLColckScene_hpp */
