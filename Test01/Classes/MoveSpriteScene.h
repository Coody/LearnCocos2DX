//
//  MoveSpriteScene.h
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#ifndef MoveSpriteScene_h
#define MoveSpriteScene_h

#include "cocos2d.h"

class MoveSpriteLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    static MoveSpriteLayer* create()
    {
        MoveSpriteLayer *pRet = new MoveSpriteLayer();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
private:
    cocos2d::CCLabelTTF *titleLabel;
    cocos2d::CCMenu *createSpriteMenu;
    cocos2d::CCArray *spriteArray;
    
    // 動畫
    cocos2d::CCAnimation *treeAnimation;
    cocos2d::CCSpriteFrameCache *cache;
    cocos2d::CCArray *frameArray;
    
    // 暫存指標
    cocos2d::CCSprite *recentTouchSprite;
    cocos2d::CCPoint oldPoint;
    
    void createAnimationTexture();
    void createSprite(CCObject *pSender);
    
    virtual void ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
};

#endif /* MoveSpriteScene_h */
