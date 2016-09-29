//
//  NumbersScene.h
//  Test01
//
//  Created by CoodyChou on 2016/9/23.
//
//

#ifndef NumbersScene_h
#define NumbersScene_h

#include "cocos2d.h"

class NumbersLayer : public cocos2d::CCLayerColor {
    
public:
    
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    CREATE_FUNC(NumbersLayer);
    
    void setRandomNumber( unsigned int startNumber , unsigned int endNumber );
    
private:
    
    unsigned int m_USartRandomNumber;
    unsigned int m_UEndRandomNumber;
    unsigned int m_UTapCount;
    float m_fSpeed;
    
    // touch 事件
    virtual void ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    
    void endQuickTap();
    
};

#endif /* NumbersScene_h */
