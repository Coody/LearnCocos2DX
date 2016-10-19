//
//  TitleLabelActor.h
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#ifndef TitleLabelActor_h
#define TitleLabelActor_h

#include "cocos2d.h"

class TitleLabelActor final : public cocos2d::CCLabelTTF{
    
public:
    virtual bool initWithSetting( cocos2d::CCString *titleString ,  const char *fontName , float fontSize , bool isOpacity , bool isScaleZero );
    
    static TitleLabelActor *createWithSetting( cocos2d::CCString *titleString , const char *fontName , float fontSize , bool isOpacity , bool isScaleZero  ){
        TitleLabelActor *pRet = new TitleLabelActor();
        if( pRet && pRet->initWithSetting( titleString, fontName, fontSize , isOpacity , isScaleZero  ) ){
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
        
    }
    
#pragma mark - Actions
    // 心跳 Action
    void startHeartBitAction();
    // FadeIn FadeOut Action
    void startFadeInAction(cocos2d::CCObject *targetObj,
                           cocos2d::SEL_CallFunc selResponseBlockDone);
    void startFadeOutAction(cocos2d::CCObject *targetObj,
                            cocos2d::SEL_CallFunc selResponseBlockDone);
};

#endif /* TitleLabelActor_h */
