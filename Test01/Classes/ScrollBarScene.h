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
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ScrollBarLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    float scrollMaxDistance;
    
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
    CCScale9Sprite *scrollBar;
    cocos2d::CCSprite *upButton;
    cocos2d::CCSprite *downButton;
    // 背景
    cocos2d::CCSprite *backgroundSprite;
    
    float tempBarY;
    float tempBGY;
    
    float bgMaxDistance;
    
    // 贊存指標
    CCScale9Sprite *recentSprite;
    
    // 設定背景移動距離
    void setBGMaxDistance(float tempDistance);
    
    // 取得 scrollbar 邊界的數值
    double getScrollBarY(double tempY);
    
    // 背景必須移動距離）
    float getRealMoveDistance();
    
    // touch 事件
    virtual void ccTouchesBegan( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesMoved( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesEnded( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
    virtual void ccTouchesCancelled( cocos2d::CCSet *pTouches , cocos2d::CCEvent *pEvent );
};

#endif /* ScrollBarScene_hpp */
