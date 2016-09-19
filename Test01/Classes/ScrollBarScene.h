//
//  ScrollBarScene.h
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#ifndef ScrollBarScene_h
#define ScrollBarScene_h

#include "cocos2d.h"

class ScrollBarBackgroundLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
}

class ScrollBarLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    static ScrollBarLayer *create()
    {
        ScrollBarLayer *pRet = new ScrollBarLayer();
        if ( pRet && pRet->init() ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
private:
    cocos2d::CCLabelTTF *titleLabel;
    cocos2d::CCMenu *mainMenu;
    
    // touch 事件
    virtual void ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
};

#endif /* ScrollBarScene_hpp */
